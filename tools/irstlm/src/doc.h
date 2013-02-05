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
//class managing a collection of documents for PLSA


class doc{
  bool binary;   //is file in binary format?
  mfstream* df; //doc file descriptor
  char* dfname; //doc file name
  dictionary* dict;

 public:
  int cd;      //current doc index
  int  n;      //number of docs 
  int  m;      //number of words in the current doc
  int* V;      //words in current doc
  int* N;      //frequencies in doc
  int* T;      //temporary frequencies

  doc(dictionary* d,char* docfname);
  ~doc();
  int count();
  int open();
  int save(char* fname);
  int savernd(char* fname,int num);
  int save(char* fname,int bsz);
  int reset();
  int read();
};

