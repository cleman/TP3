#include "utile.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_data(int *debut, int *fin, int *num, int N, int FinMax)
{
  srand(time(NULL));

  for (int i = 0; i < N; i++)
  {
      debut[i] = rand()%FinMax;
      fin[i] = rand()%(FinMax - debut[i])+debut[i]+1;
      num[i] = i;
  }
}

void affiche_tache(int *debut, int *fin, int *num, int N)
{
  for (int i = 0; i < N; i++)
  {
    printf("tache : %d, debut :  %d, fin : %d\n",num[i],debut[i],fin[i]);
  }
  printf("Fin de l'affichage\n");
}

int max(int a, int b)
{
  if (a > b)return (a);
  else return(b);
}

void tri_date_fin(int *debut, int *fin, int*num, int N)
{
  int min, indice;
  int temp_fin, temp_debut, temp_num;
  for (int i = 0; i < N-1; i++)
  {
    min = fin[i];
    indice = i;
    for (int j = i+1; j < N; j++)
    {
      if (fin[j] <= min)
      {
        indice = j;
        min = fin[j];
      }
    }
    temp_debut = debut[i];
    temp_fin = fin[i];
    temp_num = num[i];
    debut[i] = debut[indice];
    fin[i] = fin[indice];
    num[i] = num[indice];
    debut[indice] = temp_debut;
    fin[indice] = temp_fin;
    num[indice] = temp_num;
  }
}

void init_or_affiche_T(int *T, int N, int test)
{
  if (test == 0) //init
  {
    for (int i = 0; i < N; i++)
    {
      T[i] = 0;
    }
  }
  else
  {
    for (int i = 0; i < N; i++)
    {
      printf("%d ", T[i]);
    }
    printf("\n");
  }
}
