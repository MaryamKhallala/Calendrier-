#include <stdio.h>
#include <stdlib.h>

/****************  date_valide  *****************
Entrées:  la date :jj-mm-aaaa
Sorties: 1 ou 0
principe:
	Tester si la date est valide et retourner 1, sinon retourner 0.
**********************************************************/

  int date_valide(int jour,int mois,int annee)
  {
    if((annee<1901)||(annee>2099)||(mois<1)||(mois>12)||(jour<1)||(jour>31))
         return ((int)0);
      // traitement des cas particulers

     if((mois==2)&&((annee%4)==0))// fevrier + année bissextile
     {
         if(jour<=29)return ((int)1);
         return ((int)0);
     }
     if((mois==2)&&((annee%4)!=0)) // fevrier + année non bissextile
     {
         if(jour<=28)return ((int)1);
         return ((int)0);
     }
     if(((mois==4)||(mois==6)||(mois==9)||(mois==11))&&(jour>30))
        return ((int)0);

      return ((int)1);
  }



/****************  nombre_jour_annee  *****************
Entrées: l'annee
Sorties: le nombre des jours
principe:
	calculer le nombre des jours dans un certain nombre des années
**********************************************************/


   int nombre_jour_annee(int annee)
   {
       int nb_annee, // nombre des années
           nbr_bissext ;  // nombre des années bissextiles
        nb_annee=annee-1901;
        nbr_bissext=nb_annee/4;

        return ((int)((nb_annee*365)+nbr_bissext));
   }


/****************  nombre_jours_des_mois  *****************
Entrées: l'annee,et le moins
Sorties: la somme des jours cumulées
principe:
	la fonctions retourne la somme des jours cumulées des mois inferieurs à un mois donné
**********************************************************/


   int nombre_jours_des_mois(int mois,int annee,int * T)
   {
       if(((annee%4)==0)&&(mois>2))// bissextile
        return ((int)(T[mois-2]+1));
       return ((int)T[mois-2]);
   }


/************ AUTRE MANIERE DE FAIRE  ************

la fonction prend le mois et le resultat d'un test si l'annee est bissextile
Sortie :  le nombre des jours du mois donnee.

**************************************************/

     int traduct(int mois , int test)
     {
         if(((mois==4)||(mois==6)||(mois==9)||(mois==11)))
            return ((int)30);

         if((mois==2)&&test) return ((int)29);

         if(mois==2) return ((int)28);
         return ((int)31);
     }


/****************  nomb_j_m_extension  *****************
Entrées: l'annee,et le moins
Sorties: la somme des jours des moins
principe:
	la fonction fait la sommme des jours des mois inferieur au mois passé au paramètres
**********************************************************/


   int nomb_j_m_extension(int mois , int annee )
   {
       int i, s=0 ,test=0;

       if((annee%4)==0)test=1;

       for(i=1 ; i<=(mois-1) ; i++)
       {
         s += traduct(i,test);
       }
       return ((int)s);
   }


/****************  nombre_jour  *****************
Entrées: jour
Sorties: le nombre des jours
principe:
	la fonction fait le calcule des nombres de jours
**********************************************************/


   int nombre_jour(int jour)
   {
       return ((int)(jour-1));
   }

/****************  total_jours  *****************
Entrées: jour,mois,annee
Sorties: totale des jours
principe:
	la fonction fait le calcule de totale des jours
**********************************************************/

   int total_jours(int jour, int mois,int annee,int *T)
   {
       int total= (nombre_jour(jour)+ nombre_jours_des_mois(mois,annee,T) +nombre_jour_annee(annee));
       return ((int)(total%7));
   }

/****************  nom_jour  *****************
Entrées: le jour
Sorties: le nom de jours
principe:
	la fonction permet d'afficher le nom de jours
**********************************************************/

   void nom_jour(int resultat,char **T)
   {
      printf("\n %s",T[resultat]);
   }

/****************  afficher_calendrier  *****************
Entrées: le mois,l'année
principe:
	la fonction permet d'afficher le calendrier d'un mois
**********************************************************/

        void afficher_calendrier(int mois , int annee,int *T)
        {
            int test=0;
            if(annee%4==0)test++;
            // zwaaaaaa9
            for(int k=0;k<=50;k++)printf('_');
            printf('\n');

            printf("\nLun");
            printf("\tMar");
            printf("\tMerc");
            printf("\tJeu");
            printf("\tven");
            printf("\tsam");
            printf("\tdim \n");
            // zwaaaaa9 tani
            for(int k=0;k<50;k++)printf('_');
            printf("\n");

            int val=total_jours(1,mois,annee,T);

            for(int i=7-val;i<=7;i++)
               { if(i==1)break;
                 printf("\t");
               }

            for(int j=1;j<=traduct(mois,test);j++)
            {

                if(total_jours(j,mois,annee,T)==5)
                {
                    printf("%d\n",j);
                }
                else
                printf("%d\t",j);

            }
            // pour bien organiser
            printf("\n");
            for(int k=0;k<50;k++)printf("_");
            printf("\n");

        }

 /****************  nommage  *****************
Entrées: le mois
Sorties: le nom de mois
principe:
	la fonction permet d'afficher le nom de mois
**********************************************************/

                void nommage(int mois)
                {
                    switch(mois)
                    {
                        case 1: printf("\nJANVIER\n");break;
                        case 2: printf("\nFEVRIER\n");break;
                        case 3: printf("\nMARS\n");break;
                        case 4: printf("\nAVRIL\n");break;
                        case 5: printf("\nMAI\n");break;
                        case 6: printf("\nJUIN\n");break;
                        case 7: printf("\nJUILLET\n");break;
                        case 8: printf("\nAOUT\n");break;
                        case 9: printf("\nSEPTEMBRE\n");break;
                        case 10: printf("\nOCTOBRE\n");break;
                        case 11: printf("\nNOVENMBRE\n");break;
                        case 12: printf("\nDECEMBRE\n");break;
                    }
                }
 /****************  afficher_calendrier_annee  *****************
Entrées: l'année
Sorties: le nom de mois
principe:
	la fonction permet d'afficher le calendrier de l'année
**********************************************************/

       void afficher_calendrier_annee(int annee,int *T)
       {
           if((annee<1901)||(annee>2099))
           {
               printf("annee invalide \n");
               return ;
           }
           for(int j=1 ; j<=12 ; j++)
           {
               nommage(j);
               afficher_calendrier(j,annee,T);
               printf("\n");
           }
       }

  /* ********************************************************************* */

int main()
{
     char *jour[8]={"mardi","mercredi","jeudi","vendredi","samedi","dimanche","lundi"}; // tableau des jours
     int nb_jour[11]={31,59,90,120,151,181,212,243,273,304,334};  // tableau des sommes cumulées
     int jr,mois,annee,reponse=1;


     while(reponse) // tant qu'on vaut refaire le traitement
     {

        printf("\n entrer un jour :\t"); // demander le jour
        scanf("%d",&jr);
        printf("\n entrer un mois :\t"); // demander le mois
        scanf("%d",&mois);
        printf("\n entrer une annee :\t"); // demander l'annee
        scanf("%d",&annee);

        if(date_valide(jr,mois,annee))                  // si la date est valide
          {
                nom_jour(total_jours(jr,mois,annee,nb_jour),jour);
                printf("\n");
                afficher_calendrier(mois,annee,nb_jour);
          }
        else                                            // date invalide
            printf("choix de date invalide\n");

        printf("\n pour quitter , entrer 0 \n pour continuer tapper un nombre qlcq:\t"); // repeter le processus
        scanf("%d",&reponse);

        if(!reponse)break;
     }


    return 0;
}


