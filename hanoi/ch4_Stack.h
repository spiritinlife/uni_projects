/***************************************************************************
Arxeio epikefalidas	: ch4_Stack.h
Syggrafeas			: Y. Cotronis
Skopos				: Ylopoihsh me pinaka, ATD Stoiva me Merikh Apokrypsh
Ana8ewrhsh          : X. Georgakopoylos, S. Gkiokas
****************************************************************************/

#ifndef __CH4_STACK__ 
#define __CH4_STACK__

/*dhlwseis typwn*/


#include "TStoixeioyStoivas.h"


typedef struct TStoivas *HandleStoivas; /*orismos typedef tou handle pou orizetai ws deikths se stoiva kai etsi o pelaths den mporei na allazei amesa ta dedomena ths stoivas */

/*dhlwseis synarthsewn*/

HandleStoivas Stoiva_dimiourgia();

void Stoiva_Destructor(HandleStoivas * StoivaPtrPtr);
int  Stoiva_keni(HandleStoivas stoiva);
void Stoiva_othisi(HandleStoivas stoiva,TStoixeioyStoivas stoixeio,int *yperxeilisi);
void Stoiva_PopValue(HandleStoivas stoiva, TStoixeioyStoivas *stoixeio, int *ypoxeilisi);
void Stoiva_PopState(HandleStoivas stoiva, int *ypoxeilisi);

#endif /*#ifndef __CH4_STACK__ */
