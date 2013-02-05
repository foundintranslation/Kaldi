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

class plsa{
  int topics;      //number of topics
  int maxdocs;     //max number of docs
  
  dictionary* dict;
  float **T;
  float **W;
  float *H;
  
  char *tfname;
  char *wfname;
  char *hinfname;
  char *houtfname;
  char *basefname;
  char *featfname;
  
public:
  plsa(dictionary* dictfile,int top,
       char* baseFile, char* featFile,char* hfile,char* wfile,char* tfile);

  ~plsa(){
    //destroy W
    for (int i=0;i<dict->size();i++){
      delete W[i];delete T[i];
    }
    delete [] W;
    delete [] H;
    delete [] T;
  }
  
  int saveW(char* fname);
  int  saveT(char* fname);
  int combineT(char* tlist);
  int saveWtxt(char* fname);
  int loadW(char* fname);
  
  int initW(float noise,int spectopic);
  int initH(float noise,int maxdoc);
  
  int train(char *trainfile,int maxiter,float noiseH,int flagW=0,float noiseW=0,int spectopic=0);
  
  int saveFeat(char* fname);

};


