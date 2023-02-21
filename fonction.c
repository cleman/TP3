#include <stdio.h>
#include "fonction.h"
#include "utile.h"

int der(int *debut, int *fin, int j)
{
  for (int i = j-1; i >= 0; i--)
  {
    if (fin[i] < debut[j])return(i);
  }
  return(0);
}

int calcule_OPT_1(int *debut, int *fin, int j)
{
  int sortie;
  if (j == 0)
  {
    sortie = 0;
  }
  else
  {
    sortie = (max(1+calcule_OPT_1(debut, fin, der(debut, fin, j)), calcule_OPT_1(debut, fin ,j-1)));
  }
  printf("valeur : %d\n", sortie);
  return(sortie);
}