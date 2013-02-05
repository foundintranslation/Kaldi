#! /usr/bin/perl

#*****************************************************************************
# IrstLM: IRST Language Model Toolkit
# Copyright (C) 2007 Marcello Federico, ITC-irst Trento, Italy

# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.

# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.

# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA

#******************************************************************************



#first pass: read dictionary and generate 1-grams
#second pass: 
#for n=2 to N
#  foreach n-1-grams
#      foreach  n-grams with history n-1
#          compute smoothing statistics
#          store successors
#      compute back-off probability
#      compute smoothing probability
#      write n-1 gram with back-off prob 
#      write all n-grams with smoothed probability

use strict;
use Getopt::Long "GetOptions";

my $gzip=`which gzip 2> /dev/null`;
my $gunzip=`which gunzip 2> /dev/null`;
chomp($gzip);
chomp($gunzip);
my $cutoffword="<CUTOFF>"; #special word for Google 1T-ngram cut-offs 
my $cutoffvalue=39;   #cut-off threshold for Google 1T-ngram cut-offs 

#set defaults for optional parameters
my ($verbose,$size,$ngrams,$sublm)=(0, 0, undef, undef);
my ($witten_bell,$good_turing,$kneser_ney,$improved_kneser_ney)=(0, 0, "", "");
my ($witten_bell_flag,$good_turing_flag,$kneser_ney_flag,$improved_kneser_ney_flag)=(0, 0, 0, 0);
my ($freqshift,$prune_singletons,$cross_sentence)=(0, 0, 0);

my $help = 0;
$help = 1 unless
  &GetOptions('size=i' => \$size,
	      'freq-shift=i' => \$freqshift, 
	      'ngrams=s' => \$ngrams,
	      'sublm=s' => \$sublm,
	      'witten-bell' => \$witten_bell,
	      'good-turing' => \$good_turing,
	      'kneser-ney=s' => \$kneser_ney,
	      'improved-kneser-ney=s' => \$improved_kneser_ney,
	      'prune-singletons' => \$prune_singletons,
	      'cross-sentence' => \$cross_sentence,
	      'help' => \$help,
	      'verbose' => \$verbose);


if ($help || !$size || !$ngrams || !$sublm) {
  print "build-sublm.pl <options>\n",
    "--size <int>          maximum n-gram size for the language model\n",
    "--ngrams <string>     input file or command to read the ngram table\n",
    "--sublm <string>      output file prefix to write the sublm statistics \n",
    "--freq-shift <int>    (optional) value to be subtracted from all frequencies\n",
    "--witten-bell        (optional) use witten bell linear smoothing (default)\n",
    "--kneser-ney <string> (optional) use kneser-ney smoothing with statistics in <string> \n",
    "--improved-kneser-ney <string> (optional) use improved kneser-ney smoothing with statistics in <string> \n",
    "--good-turing        (optional) use good-turing linear smoothing\n",
    "--prune-singletons   (optional) remove n-grams occurring once, for n=3,4,5,... (disabled by default)\n",
    "--cross-sentence     (optional) include cross-sentence bounds (disabled by default)\n",
    "--verbose            (optional) print debugging info\n",
    "--help               (optional) print these instructions\n";    

  exit(1);
}

$witten_bell_flag = 1 if ($witten_bell);
$good_turing_flag = 1 if ($good_turing);
$kneser_ney_flag = 1 if ($kneser_ney);
$improved_kneser_ney_flag = 1 if ($improved_kneser_ney);
$witten_bell = $witten_bell_flag = 1 if ($witten_bell_flag + $kneser_ney_flag + $improved_kneser_ney_flag + $good_turing_flag) == 0;

warn "build-sublm: size $size ngrams $ngrams sublm $sublm witten-bell $witten_bell kneser-ney $kneser_ney improved-kneser-ney $improved_kneser_ney good-turing $good_turing prune-singletons $prune_singletons cross-sentence $cross_sentence\n" if $verbose;

die "build-sublm: value of --size must be larger than 0\n" if $size<1;
die "build-sublm: choose only one smoothing method\n" if ($witten_bell_flag + $kneser_ney_flag + $improved_kneser_ney_flag + $good_turing_flag) > 1;

my $log10=log(10.0);	   #service variable to convert log into log10
my $oldwrd="";		   #variable to check if 1-gram changed 
my @cnt=();		   #counter of n-grams
my $totcnt=0;		   #total counter of n-grams
my ($ng,@ng);		   #read ngrams
my $ngcnt=0;		   #store ngram frequency
my $n;

warn "Collecting 1-gram counts\n";

open(INP,"$ngrams") || open(INP,"$ngrams|")  || die "cannot open $ngrams\n";
open(GR,"|$gzip -c >${sublm}.1gr.gz") || die "cannot create ${sublm}.1gr.gz\n";

while ($ng=<INP>) {
  
  chomp($ng);  @ng=split(/[ \t]+/,$ng);  $ngcnt=(pop @ng) - $freqshift;
  
  if ($oldwrd ne $ng[0]) {
    printf (GR "%s %s\n",$totcnt,$oldwrd) if $oldwrd ne '';
    $totcnt=0;$oldwrd=$ng[0];
  }
  
  #update counter
  $totcnt+=$ngcnt;
}

printf GR "%s %s\n",$totcnt,$oldwrd;
close(INP);
close(GR);

my (@h,$h,$hpr);	      #n-gram history 
my (@dict,$code);	      #sorted dictionary of history successors
my ($diff,$singlediff,$diff1,$diff2,$diff3); #different successors of history
my (@n1,@n2,@n3,@n4,@uno3);  #IKN: n-grams occurring once or twice ...
my (@beta,$beta);	     #IKN: n-grams occurring once or twice ...
my $locfreq;

#collect global statistics for (Improved) Kneser-Ney smoothing
if ($kneser_ney || $improved_kneser_ney) {
  my $statfile=$kneser_ney || $improved_kneser_ney;
  warn "load \& merge IKN statistics from $statfile \n";
  open(IKN,"$statfile") || open(IKN,"$statfile|")  || die "cannot open $statfile\n";
  while (<IKN>) {
    my($lev,$n1,$n2,$n3,$n4,$uno3)=$_=~/level: (\d+)  n1: (\d+) n2: (\d+) n3: (\d+) n4: (\d+) unover3: (\d+)/;
    $n1[$lev]+=$n1;$n2[$lev]+=$n2;$n3[$lev]+=$n3;$n4[$lev]+=$n4;$uno3[$lev]+=$uno3;
  }
  for (my $lev=1;$lev<=$#n1;$lev++) {
    warn "level $lev: $n1[$lev] $n2[$lev]  $n3[$lev] $n4[$lev] $uno3[$lev]\n";
  }
  close(IKN);
}


warn "Computing n-gram probabilities:\n"; 

foreach ($n=2;$n<=$size;$n++) {
	
  $code=-1;@cnt=(); @dict=(); $totcnt=0;$diff=0; $singlediff=1; $diff1=0; $diff2=0; $diff3=0; $oldwrd=""; 
	
  #compute smothing statistics         
  my (@beta,$beta);               
	
  if ($kneser_ney) {
    if ($n1[$n]==0 || $n2[$n]==0) {
      warn "Error in Kneser-Ney smoothing statistics: resorting to Witten-Bell\n";
      $beta=0;  
    } else {
      $beta=$n1[$n]/($n1[$n] + 2 * $n2[$n]); 
      warn "beta $n: $beta\n";
    }
  }
	
  if ($improved_kneser_ney) {
		
    my $Y=$n1[$n]/($n1[$n] + 2 * $n2[$n]);
		
    if ($n3[$n] == 0 || $n4[$n] == 0 || $n2[$n] <= $n3[$n] || $n3[$n] <= $n4[$n]) {
      warn "Warning: higher order count-of-counts are wrong\n";
      warn "Fixing this problem by resorting only on the lower order count-of-counts\n";      
      $beta[1] = $Y;
      $beta[2] = $Y;
      $beta[3] = $Y;
    } else {
      $beta[1] = 1 - 2 * $Y * $n2[$n] / $n1[$n];
      $beta[2] = 2 - 3 * $Y * $n3[$n] / $n2[$n];
      $beta[3] = 3 - 4 * $Y * $n4[$n] / $n3[$n];
    }
  }
	
  open(HGR,"$gunzip -c ${sublm}.".($n-1)."gr.gz|") || die "cannot open ${sublm}.".($n-1)."gr.gz\n";
  open(INP,"$ngrams") || open(INP,"$ngrams|")  || die "cannot open $ngrams\n";
  open(GR,"|$gzip -c >${sublm}.${n}gr.gz");
  open(NHGR,"|$gzip -c > ${sublm}.".($n-1)."ngr.gz") || die "cannot open ${sublm}.".($n-1)."ngr.gz";

  my $ngram;
  my ($reduced_h, $reduced_ng) = ("", "");

  $ng=<INP>; chomp($ng); @ng=split(/[ \t]+/,$ng); $ngcnt=(pop @ng) - $freqshift;
  $h=<HGR>; chomp($h); @h=split(/ +/,$h); $hpr=shift @h;
  $reduced_ng=join(" ",@ng[0..$n-2]);
  $reduced_h=join(" ",@h[0..$n-2]);
        
  @cnt=(); @dict=();
  $code=-1; $totcnt=0; $diff=0; $singlediff=1; $diff1=0; $diff2=0; $diff3=0; $oldwrd=""; 

  do{
		
    #load all n-grams starting with history h, and collect useful statistics 
		
    while ($reduced_h eq $reduced_ng){ #must be true the first time!  
      #print join(" ",@h[0..$n-2]),"--",join(" ",@ng[0..$n-1]),"--\n";
      #print "oldwrd $oldwrd -- code $code\n";
			 
      if ($oldwrd ne $ng[$n-1]) { #could this be otherwise? [Marcello 22/5/09]
	$dict[++$code]=$oldwrd=$ng[$n-1];
	$diff++;
	$singlediff++ if $ngcnt==1;
      }

      if ($diff>1 && $ng[$n-1] eq $cutoffword) { # in google n-grams
	#find estimates for remaining diff and singlediff
				#proportional estimate
	$diff--;		#remove cutoffword
	my $concentration=1.0-($diff-1)/$totcnt;
	my $mass=1;		#$totcnt/($totcnt+$ngcnt);
	my $index=(1-($concentration * $mass))/(1-1/$cutoffvalue) + (1/$cutoffvalue);
	my $cutoffdiff=int($ngcnt * $index);
	$cutoffdiff=1 if $cutoffdiff==0;
				#print "diff $diff $totcnt cutofffreq $ngcnt -- cutoffdiff: $cutoffdiff\n";
				#print "concentration:",$concentration," mass:", $mass,"\n";
	$diff+=$cutoffdiff;
      }
      $cnt[$code]+=$ngcnt; $totcnt+=$ngcnt;  

      $ng=<INP>;
      if (defined($ng)){
        chomp($ng);
        @ng=split(/[ \t]+/,$ng);$ngcnt=(pop @ng) - $freqshift;  
	$reduced_ng=join(" ",@ng[0..$n-2]);
      }else{
        last;
      }
    }		
		
    if ($improved_kneser_ney) { 
      for (my $c=0;$c<=$code;$c++) {
	$diff1++ if $cnt[$c]==1;
	$diff2++ if $cnt[$c]==2;
	$diff3++ if $cnt[$c]>=3;
      }
    }
		
    #print smoothed probabilities
		
    my $boprob=0;		#accumulate pruned probabilities 
    my $prob=0;
		
    for (my $c=0;$c<=$code;$c++) {
			
      if ($kneser_ney && $beta>0) {
	$prob=($cnt[$c]-$beta)/$totcnt;
      } elsif ($improved_kneser_ney) {
	my $b=($cnt[$c]>= 3? $beta[3]:$beta[$cnt[$c]]);
	$prob=($cnt[$c] - $b)/$totcnt;
      } elsif ($good_turing && $singlediff>0) {
	$prob=$cnt[$c]/($totcnt+$singlediff);
      } else {
	$prob=$cnt[$c]/($totcnt+$diff);
      }
			
      $ngram=join(" ",$reduced_h,$dict[$c]);
			
      #rm singleton n-grams for (n>=3), if flag is active
      #rm n-grams (n>=2) containing cross-sentence boundaries, if flag is not active
      #rm n-grams containing <unk> or <cutoff> except for 1-grams

      #warn "considering $size $n |$ngram|\n";
      if (($prune_singletons && $n>=3 && $cnt[$c]==1) ||
	  (!$cross_sentence && $n>=2 && &CrossSentence($ngram)) ||
	  ($dict[$c]=~/<UNK>/i) || ($n>=2 && $h=~/<UNK>/i) ||	
	  ($dict[$c] eq $cutoffword) 
	 ) {	
					
	$boprob+=$prob;
					
	if ($n<$size) {	#output this anyway because it will be an history for n+1 
	  printf GR "%f %s %s\n",-10000,$reduced_h,$dict[$c];
	}
      } else {			# print unpruned n-1 gram
	printf(GR "%f %s %s\n",log($prob)/$log10,$reduced_h,$dict[$c]);
      }
    }
		
    #rewrite history including back-off weight
    print "$reduced_h --- $h --- $reduced_ng --- $ng --- $totcnt $diff \n" if $totcnt+$diff==0 && defined($ng);
        
    #check if history has to be pruned out
    if ($hpr==-10000) {
      #skip this history
    } elsif ($kneser_ney && $beta>0) {
      printf NHGR "%s %f\n",$h,log($boprob+($beta * $diff/$totcnt))/$log10;
    } elsif ($improved_kneser_ney) {
      my $lambda=($beta[1] * $diff1 + $beta[2] * $diff2 + $beta[3] * $diff3)/$totcnt; 	  
      printf NHGR "%s %f\n",$h,log($boprob+$lambda)/$log10;
    } elsif ($good_turing && $singlediff>0) {
      printf NHGR "%s %f\n",$h,log($boprob+($singlediff/($totcnt+$singlediff)))/$log10;
    } else {
      printf NHGR "%s %f\n",$h,log($boprob+($diff/($totcnt+$diff)))/$log10;
    }     
		
    #reset smoothing statistics
    $code=-1;@cnt=(); @dict=(); $totcnt=0;$diff=0;$singlediff=0;$oldwrd="";$diff1=0;$diff2=0;$diff3=0;$locfreq=0;
		
    #read next history
    $h=<HGR>;
    if (defined($h)){
      chomp($h); @h=split(/ +/,$h); $hpr=shift @h;
      $reduced_h=join(" ",@h[0..$n-2]);
    }else{
      die "ERROR: Somehing could be wrong: history are terminated before ngrams!" if defined($ng);
    }
  }until (!defined($ng));		#n-grams are over
	
  close(HGR); close(INP); close(GR); close(NHGR);
  rename("${sublm}.".($n-1)."ngr.gz","${sublm}.".($n-1)."gr.gz");
}   


#check if n-gram contains cross-sentence boundaries
#this happens if
# either <s> occurs not only in the first place
# or     </s> occurs not only in thes last place

sub CrossSentence(){
  my ($ngram) = @_;
# warn "check CrossSentence |$ngram|\n";
  if (($ngram=~/ <s>/i) || ($ngram=~/<\/s> /i)) { 
#    warn "delete $ngram\n";
    return 1;
  }
  return 0;
}
