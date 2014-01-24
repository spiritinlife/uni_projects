/***************************************************************************
Arxeio epikefalidas	: TStoixeioyStoivas.h
Syggrafeas			: Y. Cotronis
Skopos				: Orizei ton Typo Stoixeioy ths Stoivas (int)
Ana8ewrhsh          : X. Georgakopoylos, S. Gkiokas
****************************************************************************/
#ifndef __TStoixeioyStoivas_H__
#define __TStoixeioyStoivas_H__
#include <stdio.h>

typedef struct {
      int aktina;
      int height;
      }ogkos;
typedef ogkos TStoixeioyStoivas;

int mikrotero(TStoixeioyStoivas left, TStoixeioyStoivas right);
void TSstoiva_setValues (TStoixeioyStoivas *target, TStoixeioyStoivas source);
int TSstoiva_readValue (FILE *from,  TStoixeioyStoivas *Elem);
void TSstoiva_writeValue (FILE *to, TStoixeioyStoivas Elem);
#endif
