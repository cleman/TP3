#include <stdio.h>
#include "fonction2.h"
#include "utile.h"

/*
Les fonctions de ce fichier permettent de calculer le nombre minimum de machine
nécessaire pour réaliser toutes les tâches selon les dates de debut et de fin.
La première fonction calcul le nombre nécessaire en testant la disponibilités des machines,
et la deuxième fonction donne le nombre en calculant la profondeur
*/

//Calcul nombre machine nécessaire
int fc1_ex3(int *debut, int *fin, int N)
{
  int nb_mach = 1;    //nombre machine
  int fin_int[N];     //fin de l'intervalle occupé pour la machine i
  init_or_affiche_T(fin_int, N, 0);
  fin_int[0] = fin[0];
  char test;
  for (int i = 1; i < N; i++)
  {
    test = 0;
    for (int id = 0; id < nb_mach; id++)
    {
      if (test == 0 && debut[i] >= fin_int[id])
      {
        test = 1;
        fin_int[id] = fin[i];
      }
    }
    if (test == 0)
    {
      nb_mach++;
      fin_int[nb_mach] = fin[i];
    }
  }
  return (nb_mach);
}

//Calcul de la profondeur du probleme (Q3.2)
int calcul_profondeur(int *debut, int *fin, int N)
{
  int profondeur = 0;         //Initialisation profondeur
  int pmax = profondeur;      //Profondeur max
  for (int i = 0; i < N; i++)
  {
    profondeur = 0;
    for (int j = 0; j < N; j++) //Calcul de la profondeur en 1 point
    {
      if (debut[j] < i && fin[j] > i)profondeur++;
    }
    if (profondeur > pmax)pmax = profondeur;  //Mise à jour profondeur max
  }
  return (pmax);
}

//Sous-main pour l'exercice 1
void appel_ex3()
{
  int FinMax = 20;
  int N = 10;
  int debut[N];
  int fin[N];
  int num_tache[N];

  init_data(debut, fin, num_tache, N, FinMax);  //Definition date debut et fin
  tri_date_fin(debut, fin, num_tache, N);   //Tri croissant selon date de fin
//  affiche_tache(debut, fin, num_tache, N);    //Affichage du tableau des taches
  int p = fc1_ex3(debut, fin, N);   //Nombre de machine nécessaire
  int p2 = calcul_profondeur(debut, fin, N);  //Profondeur calculé
  printf("Nombre de machine necessaire : %d\nProfondeur calculé : %d\n",p,p2);
}
