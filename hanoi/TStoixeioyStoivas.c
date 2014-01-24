/***************************************************************************
Arxeio ylopihshs	: TStoixeioyStoivas.c
Syggrafeas			: Y. Cotronis
Skopos				: Ylipoiei praxeis toy Typoy Stoixeioy ths Stoivas (int)
Ana8ewrhsh          : X. Georgakopoylos, S. Gkiokas
****************************************************************************/
#include "TStoixeioyStoivas.h"
#define p 3.14

int mikrotero(TStoixeioyStoivas left, TStoixeioyStoivas right)
{
/* Epistrefei 1 an to stoixeio left einai mikrotero tou right */
int ogosL,ogosR;
ogosL=p*left.aktina*left.aktina*left.height;
ogosR=p*right.aktina*right.aktina*right.height;
   return (ogosL<ogosR);
} 


void TSstoiva_setValues (TStoixeioyStoivas *target, TStoixeioyStoivas source)
{
	target->aktina=source.aktina;
        target->height=source.height;
}

int TSstoiva_readValue (FILE *from, TStoixeioyStoivas *ElemPtr)
{
     if (fscanf(from, "%d %d", &ElemPtr->aktina,&ElemPtr->height)==EOF)
         return -1; /*An h fscanf epistrepsei EOF tote gurname -1 kai etsi gnwrizoume oti to arxeio dene xei alla dedomena */  
}

void TSstoiva_writeValue (FILE *to, TStoixeioyStoivas Elem)
{
	fprintf(to, "%d		%d	ogos=%f\n", Elem.aktina,Elem.height,Elem.aktina*Elem.aktina*Elem.height*p);  
/* Prosthesa to \n gia na einai pio euanagnwsto  kai na fenetai san sthlh*/
}
