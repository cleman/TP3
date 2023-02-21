#include "utile.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_data(int *debut, int *fin, int N, int FinMax)
{
  srand(time(NULL));

  for (int i = 0; i < N; i++)
  {
      debut[i] = rand()%FinMax;
      fin[i] = rand()%(FinMax - debut[i])+debut[i]+1;
  }
}

void affiche_tache(int *debut, int *fin, int N)
{
  for (int i = 0; i < N; i++)
  {
    printf("tache %d, debut :  %d, fin : %d\n",i,debut[i],fin[i]);
  }
}

int max(int a, int b)
{
  if (a > b)return (a);
  else return(b);
}
