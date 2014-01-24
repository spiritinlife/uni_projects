/*****************************************************
Arxeio ylopoihshs	        : Hanoi.c
Syggrafeas			:Γιώργος Χαϊλαζόπουλος
Skopos				: Skeleton program gia Ylopoihsh Algorithmoy Hanoi me Stoives
******************************************************/

#include <stdio.h>
#include "ch4_Stack.h"
#include "TStoixeioyStoivas.h"

int Input(FILE * from, HandleStoivas S, int *n);
void Output(FILE * to, HandleStoivas S);
void Move(HandleStoivas from, HandleStoivas to);
void recursiveHanoi(int level, HandleStoivas from, HandleStoivas to, HandleStoivas with);



int main(int argc,char **argv){
    FILE *from,*to;    /* Oi deiktes st arxeia */
    int megethos_stoivas1,i; 
    HandleStoivas stoiva1,stoiva2,voithitiki_stoiva; /* Autoi einai oi deiktes stis stoives mesw Handle etsi wste na mhn borei o pelaths na diaxhristei amesa ta dedomena tous */


    stoiva1=Stoiva_dimiourgia();          /*Dhmiourgountai oi treis stoives pou antiprosopevoun */
    stoiva2=Stoiva_dimiourgia();          /*tis steiles tou Anoi */
    voithitiki_stoiva=Stoiva_dimiourgia();

    if (argc==2)
       from=fopen(argv[1],"r"); /*Tropos anoigmatos arxeiou apo thn grammh entolwn */
    else
       from=fopen("AktinaYpsos.txt","r"); /* Tropos anoigmatos arxeiou apo to kwdika*/

    to=fopen("write_here.txt","w"); /*Arxei sto opoio grafei h sunarthsh Output*/
    if (Input(from,stoiva1,&megethos_stoivas1)==1)/*H Input diavazei ta dedomena apo th from kai */
       return 1;                              /*ta wthei sthn stoiva  elegxontas gia yperxeilisi*/  

    recursiveHanoi(megethos_stoivas1,stoiva1,stoiva2,voithitiki_stoiva); /*Kanei thn metafora apo thn stoiva1 sthn stoiva 2*/
    Output(to,stoiva2); /* H output grafei ta stoixeia ths stoiva2 sto to pou antiprwsopeuei */
                            /*to write_here.txt */
    fclose(from);       /*Kleinoume to arxeio from*/
    fclose(to);         /*Kleinoume to arxeio to */
    Stoiva_Destructor(&stoiva1); /* Apodesmeuoume thn mnhmh */
    Stoiva_Destructor(&stoiva2);
    Stoiva_Destructor(&voithitiki_stoiva);
 return 0;   /* An ola exoun paei kala epistrefei 0*/ 
   }   
 

   
int Input(FILE *from, HandleStoivas S, int *n) {
/* Diavazei stoixeia apo to from kai ta wthei sthn S. 
   Epistrefei ton arithmo twn stoixeiwn poy wthhse
*/

  *n=0;
  TStoixeioyStoivas ElemPtr,stoivaA_korifis;
  int yperxeilisi,ypoxeilisi;
  while (TSstoiva_readValue(from,&ElemPtr)!=-1)/*diavazei ena dedomeno kathe fora apo to fromkai*/ 
      {                                  /*to apothikeuei sto ElemPtr mexri na sunanthsei to EOF*/ 
      if (Stoiva_keni(S)==1)/*An h stoiva einai kenh tote apo ton kanona 2 mporoume na*/ 
         {                  /*wthisoume to neo dedomeno */
         Stoiva_othisi(S,ElemPtr,&yperxeilisi); /*Ginete h wthish tou ElemPtr sthn stoiva*/ 
         if (yperxeilisi==1){                   /*elegxontas gia yperxeilisi*/
            printf("Egine yperxeilisi!!\n"); 
            return 1;
            }
         (*n)++; /* Akoma ena stoixeio mphke sthn sthlh */
         }
       else if (Stoiva_keni(S)==0) /*An h stoiva den einai keni */
         {          
         Stoiva_PopValue(S,&stoivaA_korifis,&ypoxeilisi); /* mporoume na paroume to stoixeio ths */
                                                          /*korifis ths stoivas */
         if (mikrotero(ElemPtr,stoivaA_korifis)){  /* kai na to sugrinoume me to ElemPtr*/
            Stoiva_othisi(S,ElemPtr,&yperxeilisi); /*Sumfwna me ton kanona 2 mporoume na to */
            if (yperxeilisi==1){                   /*wthisoume an ElemPtr<stoiva_korifis*/
               printf("Egine yperxeilisi!!\n");    /*elegxontas gia yperxeilisi ths stoivas*/
               return 1;
               }
            (*n)++; /* Akoma ena stoixeio mphke sthn sthlh */
            }
         }
       }
return 0; /*An ola exoun paei kala epistrefei 0*/
  }

void Move(HandleStoivas Source, HandleStoivas Target) {
       
/* Metaferei ena stoixeio apo thn stoiva Source sthn Target */
int yperxeilisi,ypoxeilisi;
TStoixeioyStoivas stoixeio;
Stoiva_PopValue(Source,&stoixeio, &ypoxeilisi); /*Pairnoume to stoixeio ths korifis ths stoivas*/
Stoiva_PopState(Source, &ypoxeilisi);/*Allazoume thn katastash ths stoivas dhladh meiwnoume thn*/  
                                     /*korifi kata 1*/
Stoiva_othisi(Target,stoixeio,&yperxeilisi); /*Wthoume to stoixeio auto sthn allh stoiva*/
                                             /*elegxontas gia uperxeilisi */

}


void recursiveHanoi(int level, HandleStoivas from,HandleStoivas to, HandleStoivas with) {
/* Level einai o arithmos twn diskwn kai 
   from o arxikh stoiva , to h telikh kai with h bohuhtikh 
*/
     if (level >= 1) {
        recursiveHanoi(level - 1, from, with, to);
        Move(from, to);
        recursiveHanoi(level - 1, with, to, from);
        }
     }

void Output(FILE *to, HandleStoivas S){
/* Exagei stoixeia apo thn S kai ta ektypvnei sto to */
int ypoxeilisi;
TStoixeioyStoivas stoixeio;
Stoiva_PopValue(S, &stoixeio, &ypoxeilisi); /*Pairnw to stoixeio ths korifis ths stoivas */
while(ypoxeilisi!=1){/*Otan apo thn Stoiva_PopValue ginei ypoxeilisi=1 shmainei oti den exei allo*/
                     /*stoixeio h stoiva */
     Stoiva_PopState(S, &ypoxeilisi); /* Meiwnw thn stoiva kata 1*/
     TSstoiva_writeValue (to,stoixeio); /* Grafw to stoixeio auto sto to pou einai to */
                                        /*write_here.txt*/
     Stoiva_PopValue(S, &stoixeio, &ypoxeilisi);
     }
}
