/*
ID: ammar.q2
LANG: C
TASK: milk
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct supply {
  long int price;
  long int inventory;
  
} Supply;

long int min(long int a, long int b) {
  return a < b ? a : b;
}

void swap(Supply *M, long int i, long int j) {
  M[i].price = M[i].price + M[j].price;
  M[j].price = M[i].price - M[j].price;
  M[i].price = M[i].price - M[j].price; 
  M[i].inventory = M[i].inventory + M[j].inventory;
  M[j].inventory = M[i].inventory - M[j].inventory;
  M[i].inventory = M[i].inventory - M[j].inventory; 
}

int main () {
  FILE *fin  = fopen ("milk.in", "r");
  FILE *fout = fopen ("milk.out", "w");
  long int n, f;
  fscanf(fin, "%ld %ld", &n, &f);
  
  Supply M[10000];
  long int i, j;
  for (i = 0; i < f; i++) {
    fscanf(fin, "%ld %ld", &(M[i].price), &(M[i].inventory));
    j = i-1;
    while (j+1 && (M[j].price > M[j+1].price)) {
      swap(M, j, j+1);
      j--;
    }
  }

  long int remaining = n;
  long int cost = 0;
  long int change;

  for (i = 0; i < f; i++) {
    change = min(remaining, M[i].inventory);
    cost += M[i].price * change;
    remaining -= change;
  }

  fprintf(fout, "%ld\n", cost);

  return 0;
}
