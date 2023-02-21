#include <stdio.h>
#include "fonction.h"
#include "utile.h"

#define FinMax 20

int main()
{
  int N = 10;
  int debut[] = {0, 2, 4, 5, 6, 7, 11, 11, 12, 18};
  int fin[] = {1, 5 , 6, 6, 7, 9, 12, 14, 18, 19 };

  //init_data(debut, fin, N, FinMax);
  affiche_tache(debut, fin, N);
  calcule_OPT_1(debut, fin, 9);
  printf("fini\n");

  return (0);
}