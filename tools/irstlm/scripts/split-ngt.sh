#! /bin/sh

#usage:
#ngt-split.sh <input> <output> <size> <parts>
#It creates <parts> files (named <output.000>, ... <output.999>)
#containing ngram statistics (of <order> length) in Google format
#These files are a partition of the whole set of ngrams

basedir=$IRSTLM
bindir=$basedir/bin
scriptdir=$basedir/scripts

unset par
while [ $# -gt 0 ]
do
   echo "$0: arg $1"
   par[${#par[@]}]="$1"
   shift
done

inputfile=${par[0]}
outputfile=${par[1]}
order=${par[2]}
parts=${par[3]}

dictfile=dict$$

$bindir/dict -i="$inputfile" -o=$dictfile -f=y -sort=n

$scriptdir/split-dict.pl --input $dictfile --output ${dictfile}. --parts $parts

rm $dictfile

for d in `ls ${dictfile}.*` ; do
w=`echo $d | perl -pe 's/.+(\.[0-9]+)$/$1/i'`
w="$outputfile$w"
echo "$bindir/ngt -i="$inputfile"  -n=$order -gooout=y -o=$w -fd=$d  > /dev/null"
$bindir/ngt -n=$order -gooout=y -o=$w -fd=$d -i="$inputfile"  > /dev/null
rm $d
done

exit
