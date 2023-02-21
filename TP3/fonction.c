#include <stdio.h>
#include "fonction.h"
#include "utile.h"

/*
Les fonctions de ce fichiers permettent de trouver les maximum
de taches possible à faire sur un intervalle de temps en ne
faisant qu'une seule tache à la fois.
En sortie, il est affiché un tableau T, si T[i] = 0 : tâche non sélectionne,
si T[i] = 1 : tâche sélectionné

La première fonction (calcule_OPT_1) correspondant à Q2.1 ne fonctionne pas.
calcul_OPT_2 et calcul_OPT_3 sont deux variantes de la fonction dans Q2.2
*/

//Fonction appeler dans Q2.1
int der(int *debut, int *fin, int j)
{
  for (int i = j-1; i >= 0; i--)
  {
    if (fin[i] <= debut[j])return(i);
  }
  return(0);
}

//Fonction Q2.1
int calcule_OPT_1(int *debut, int *fin, int j)
{
  if (j == 0)
  {
    return(0);
  }
  else
  {
    int element1 = 1+calcule_OPT_1(debut, fin, der(debut, fin, j));
    int element2 = calcule_OPT_1(debut, fin ,j-1);
    return( max(element1, element2) );
  }
}

//Fonction Q2.2 version 1
void calcul_OPT_2(int *debut, int *fin, int *num, int N)
{
  printf("%d\n", num[0]);
  int fin_int = fin[0];
  for (int i = 1; i < N; i++)
  {
    if (debut[i] >= fin_int)   //Test si tache commence après fin interval de travail
    {
      fin_int = fin[i];       //Modification fin interval de travail
      printf("%d\n",num[i]);  //Affichage de la nouvelle tache sélectionnée
    }
  }
}

//Fonction Q2.2 version 2 (1ere partie)
int calcul_OPT_3(int *debut, int *fin, int *num, int *T, int N, int fin_int)
{
  for (int i = 0; i < N; i++)
  {
    if (debut[i] >= fin_int)  //Test si tache commence après fin interval de travail
    {
      fin_int = fin[i];     //Modification fin interval de travail
      //printf("%d\n",num[i]);
      T[num[i]] = 1;
      return (fin_int);
    }
  }
  return(fin[N-1]);
}

//Fonction Q2.2 version 2 (2eme partie)
void appel_OPT_3(int *debut, int *fin, int *num, int *T, int N)
{
  int fin_int = 0;  //Initialisation de la fin d'interval de travail à 0
  do
  {
    fin_int = calcul_OPT_3(debut, fin, num, T, N, fin_int); //Nouvelle date de fin pour une tâche supplémentaire
  }while (fin_int < fin[N-1]);    //Fin si fin_int atteint derniere fin de tache
}

//Sous-main pour l'exercice 2
void appel_ex2()
{
  int FinMax = 200; //Date de fin maximum pour une tache
  int N = 100;      //Nombre de tâche à ordonner
  int debut[N];     //Date de debut des taches
  int fin[N];       //Date de fin des taches
  int num_tache[N]; //Numero de la tache avant tri
  int T[N];   //1 si la tache est selectionne, 0 sinon

  init_data(debut, fin, num_tache, N, FinMax);  //Initialisation date début et fin
  tri_date_fin(debut, fin, num_tache, N); //Tri selon date de fin en ordre croissant
  init_or_affiche_T(T, N, 0);       //Initialisation T à 0

//  calcule_OPT_1(debut, fin, 9);
//  calcul_OPT_2(debut, fin, num_tache, N);
  appel_OPT_3(debut, fin, num_tache, T, N); //Calcul de l'ordonnancement
  init_or_affiche_T(T, N, 1);     //Affichage du tableau T
}
