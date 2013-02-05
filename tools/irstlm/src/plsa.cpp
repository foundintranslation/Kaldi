/******************************************************************************
 IrstLM: IRST Language Model Toolkit, compile LM
 Copyright (C) 2006 Marcello Federico, ITC-irst Trento, Italy
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA
 
 ******************************************************************************/

using namespace std;

#include "mfstream.h"
#include "mempool.h"
#include "htable.h"
#include "dictionary.h"
#include "n_gram.h"
#include "ngramtable.h"
#include "doc.h"
#include "cplsa.h"
#include "cmd.h"

#define YES   1
#define NO    0

#define END_ENUM    {   (char*)0,  0 }

static Enum_T BooleanEnum [] = {
  {    "Yes",    YES }, 
  {    "No",     NO},
  {    "yes",    YES }, 
  {    "no",     NO},
  {    "y",    YES }, 
  {    "n",     NO},
  END_ENUM
};


int main(int argc, char **argv)
{
	char *dictfile=NULL; 
	char *trainfile=NULL; 
	char *adafile=NULL;
	char *featurefile=NULL;
	char *basefile=NULL;
	char *hfile="hfff"; //default filename
	char *tfile=NULL;
	char *wfile=NULL;
	char *ctfile=NULL;
	char *txtfile=NULL;
	char *binfile=NULL;
	
	int binsize=0;
	int topics=0;  //number of topics
	int st=0;      //special topic: first st dict words
	int it=0;
	int help=0;
	
	DeclareParams(
				  
				  "Dictionary", CMDSTRINGTYPE, &dictfile,
				  "d", CMDSTRINGTYPE, &dictfile,
				  
				  "Binary", CMDSTRINGTYPE, &binfile,
				  "b", CMDSTRINGTYPE, &binfile,
				  
				  "SplitData", CMDINTTYPE, &binsize,
				  "sd", CMDINTTYPE, &binsize,				  
				  
				  "Collection", CMDSTRINGTYPE, &trainfile,
				  "c", CMDSTRINGTYPE, &trainfile,
				  
				  "Model", CMDSTRINGTYPE, &basefile,
				  "m", CMDSTRINGTYPE, &basefile,
				  
				  "HFile", CMDSTRINGTYPE, &hfile,
				  "hf", CMDSTRINGTYPE, &hfile,
				  
				  "WFile", CMDSTRINGTYPE, &wfile,
				  "wf", CMDSTRINGTYPE, &wfile,
				  
				  "TFile", CMDSTRINGTYPE, &tfile,
				  "tf", CMDSTRINGTYPE, &tfile,
				  
				  "CombineTFile", CMDSTRINGTYPE, &ctfile,
				  "ct", CMDSTRINGTYPE, &ctfile,
				  
				  "TxtFile", CMDSTRINGTYPE, &txtfile,
				  "txt", CMDSTRINGTYPE, &txtfile,
				  
				  "Inference", CMDSTRINGTYPE, &adafile,
				  "inf", CMDSTRINGTYPE, &adafile,
				  
				  "Features", CMDSTRINGTYPE, &featurefile,
				  "f", CMDSTRINGTYPE, &featurefile,
				  
				  "Topics", CMDINTTYPE, &topics,
				  "t", CMDINTTYPE, &topics,
				  
				  "SpecialTopic", CMDINTTYPE, &st,
				  "st", CMDINTTYPE, &st,
				  
				  "Iterations", CMDINTTYPE, &it,
				  "it", CMDINTTYPE, &it,
				  
  				  "Help", CMDENUMTYPE, &help, BooleanEnum,
				  "h", CMDENUMTYPE, &help, BooleanEnum,
				  
				  (char *)NULL
				  );
	
	GetParams(&argc, &argv, (char*) NULL);
	
	if (argc==1 || help){
		cerr <<"plsa: IRSTLM tool for Probabilistic Latent Semantic Analysis LM inference\n\n";

		cerr <<"Usage (1): plsa -c=<collection> -d=<dictionary> -m=<model> -t=<topics> -it=<iter>\n\n";
		cerr <<"Train a PLSA model. Parameters specify collection and dictionary filenames\n";
		cerr <<"number of EM iterations, number of topics, and model filename. The collection\n";
		cerr <<"must begin with the number of documents and documents should be separated\n";
		cerr <<"with the </d> tag. The begin document tag <d> is not considered.\n";
		cerr <<"Example:\n";
		cerr <<"3\n";
		cerr <<"<d> hello world ! </d>\n";
		cerr <<"<d> good morning good afternoon </d>\n";
		cerr <<"<d> welcome aboard </d>\n\n";

		cerr <<"Usage (2): plsa -c=<text collection> -d=<dictionary> -b=<binary collection>\n\n";
		cerr <<"Binarize a textual document collection to speed-up training (1)\n";
		cerr <<"\n";
		
		cerr <<"Usage (3): plsa -d=<dictionary> -m=<model> -t=<topics> -inf=<text> -f=<features> -it=<iterations>\n\n";
		cerr <<"Infer a full 1-gram distribution from a model and a small text. The 1-gram\n";
		cerr <<"is saved in the feature file. The 1-gram\n";
		cerr <<"\n";
		exit(1);	
	}
	
	if (!dictfile)
    {
		cerr <<"Missing parameters dictionary\n";
		exit(1);
    };
	
	if (!adafile & (!trainfile || !binfile) && (!trainfile || !it || !topics || !basefile))
    {
		cerr <<"Missing parameters for training\n";
		exit(1);
    }
	
	if ((!trainfile && basefile) && (!featurefile || !adafile || !it || !topics))
    {
		cerr <<"Missing parameters for adapting\n";
		exit(1);
    }
	
	if ((adafile) && (!featurefile))
    {
		cerr <<"Missing parameters for adapting 2\n";
		exit(1);
    }
	
	dictionary dict(dictfile);
	
	cout << dict.size() << "\n";
	dict.incflag(1);
	dict.encode(dict.BoD());
	dict.encode(dict.EoD());
	dict.incflag(0);
	if (dict.oovcode()==-1){
		dict.oovcode(dict.encode(dict.OOV()));
	}
    
	cout << dict.size() << "\n";

	if (binfile){
		cout << "opening collection\n";
		doc col(&dict,trainfile);
		col.open();
		if (binsize)
			col.save(binfile,binsize);
		else
			col.save(binfile);
		exit(1);
	}
	
	system("rm -f hfff");
	
	plsa tc(&dict,topics,basefile,featurefile,hfile,wfile,tfile);
	
	if (ctfile){ //combine t
		tc.combineT(ctfile);
		tc.saveW(basefile);
		exit(1);
	}
	
	if (trainfile){
		tc.train(trainfile,it,.5,1,0.5,st);
		if (txtfile) tc.saveWtxt(txtfile);
	}
	
	if (adafile){
		tc.loadW(basefile);
		tc.train(adafile,it,.0);
	}
	if (strcmp(hfile,"hfff")==0)  system("rm -f hfff");
	
	exit(1); 
}



