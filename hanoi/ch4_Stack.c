/***************************************************************************
Arxeio ylopoihshs	        : ch4_Stack.c
Syggrafeas			: Γιώργος Χαϊλαζόπουλος
Skopos				: Ylopoihsh me pinaka, ATD Stoiva me Olikh Apokrypsh
****************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include "ch4_Stack.h"

/*orismos synarthsewn*/

#define PLITHOS 100/*megisto epitrepto plh8os stoixeiwn ana stoiva*/
typedef struct TStoivas{
	int korifi;
	TStoixeioyStoivas pinakas[PLITHOS];
}TStoivas;

HandleStoivas Stoiva_dimiourgia()
{
 /*
 *	Pro: 		Kamia
 *	Meta: 		Dhmioyrgia kenhs stoivas
*/
        HandleStoivas stoiva=malloc(sizeof(TStoivas)); /* Desmeush mnhmhs gia deikth pou deixnei */
                                                       /*se TStoivas*/
	stoiva->korifi = -1; /*Arxikopoihsh korifis */
        return stoiva;
}

void Stoiva_Destructor(HandleStoivas * stoiva)
{
       free(*stoiva); /* Apodesmeush mnhmhs */
       *stoiva=NULL;  /*Vazw ton deikth na deixnei sto NULL*/
}
int  Stoiva_keni(HandleStoivas stoiva)
{
 /*
 *	Pro: 	    Dhmioyrgia ths stoiva
 *	Meta: 		Epistrefei 1 an h stoiva einai kenh alliws 0
*/
	return (stoiva->korifi == -1);
}

void Stoiva_PopValue(HandleStoivas stoiva, TStoixeioyStoivas *stoixeio, int *ypoxeilisi)
{
/*
      Pro:                  Mh kenh stoiva
      Meta:                 Eksagei to stoixeio apo thn stoiva xwris na thn metavalei
*/
      if (Stoiva_keni(stoiva))  
         *ypoxeilisi = 1;   
      else
      {   
          *ypoxeilisi = 0;
          TSstoiva_setValues(stoixeio, stoiva->pinakas[stoiva->korifi]); /* Apothikeuei sth metavlhth stoixeio thn timh tou pinakas[korifi]*/
      }

}
void Stoiva_PopState(HandleStoivas stoiva, int *ypoxeilisi)
{
 /*
     Pro:         Mh kenh stoiva
     Meta:        Meiwnei thn korufh, alalzei dhladh mono thn katastash ths stoivas
 */

     if (Stoiva_keni(stoiva))
        *ypoxeilisi = 1;
     else
     {
        *ypoxeilisi = 0;
        stoiva->korifi--;
     }
}

void Stoiva_othisi(HandleStoivas stoiva,TStoixeioyStoivas stoixeio,int *yperxeilisi)
{
 /*
 *	Pro: 		Dhmioyrgia ths stoiva
 *	Meta: 		Wtheitai to stoixeio sth stoiva
*/
	if (stoiva->korifi == PLITHOS -1)
		*yperxeilisi = 1;
	else
	{
		*yperxeilisi = 0;
		stoiva->korifi++;
		TSstoiva_setValues(&(stoiva->pinakas[stoiva->korifi]), stoixeio);
/* debug
		printf("O|"); TSstoiva_writeValue(stoixeio); printf("|O\n");
		printf("O|"); TSstoiva_writeValue(stoiva->pinakas[stoiva->korifi]); printf("|O\n");
*/
	}
}

