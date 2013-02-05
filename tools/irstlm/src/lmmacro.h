// $Id: lmmacro.h 3461 2010-08-27 10:17:34Z bertoldi $

/******************************************************************************
IrstLM: IRST Language Model Toolkit
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


#ifndef MF_LMMACRO_H
#define MF_LMMACRO_H

#ifndef WIN32
#include <sys/types.h>
#include <sys/mman.h>
#endif

#include "util.h"
#include "ngramcache.h"
#include "dictionary.h"
#include "n_gram.h"
#include "lmtable.h"

#define MAX_TOKEN_N_MAP 4

class lmmacro: public lmtable {

  dictionary     *dict;
  int             maxlev; //max level of table
  int             selectedField;

  bool            collapseFlag; //flag for the presence of collapse
  bool            mapFlag; //flag for the presence of map

  int             microMacroMapN;
  int            *microMacroMap;
  bool           *collapsableMap;
  bool           *collapsatorMap;

#ifdef DLEXICALLM
  int             selectedFieldForLexicon;
  int            *lexicaltoken2classMap;
  int             lexicaltoken2classMapN;
#endif


  void loadmap(const std::string mapfilename);
  void unloadmap();

  bool transform(ngram &in, ngram &out);
  void field_selection(ngram &in, ngram &out);
  bool collapse(ngram &in, ngram &out);
  void mapping(ngram &in, ngram &out);

 public:

 lmmacro(float nlf=0.0, float dlfi=0.0);
 ~lmmacro();

  void load(const std::string filename,int mmap=0);

  double lprob(ngram ng); 
  double clprob(ngram ng,double* bow=NULL,int* bol=NULL,char** maxsuffptr=NULL,unsigned int* statesize=NULL); 
  double clprob(int* ng, int ngsize, double* bow=NULL,int* bol=NULL,char** maxsuffptr=NULL,unsigned int* statesize=NULL);

  const char *maxsuffptr(ngram ong, unsigned int* size=NULL);
  const char *cmaxsuffptr(ngram ong, unsigned int* size=NULL);

  void map(ngram *in, ngram *out);
  void One2OneMapping(ngram *in, ngram *out);
  void Micro2MacroMapping(ngram *in, ngram *out);
#ifdef DLEXICALLM
  void Micro2MacroMapping(ngram *in, ngram *out, char **lemma);
  void loadLexicalClasses(const char *fn);
  void cutLex(ngram *in, ngram *out);
#endif


  inline dictionary* getDict() const { return dict; }
  inline int maxlevel() const { return maxlev; };
};



#endif

