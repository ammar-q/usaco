/*
ID: ammar.q2
LANG: C
TASK: numtri
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int max(long int a, long int b) {
  return a > b ? a : b;
}

int main () {
  FILE *fin  = fopen ("numtri.in", "r");
  FILE *fout = fopen ("numtri.out", "w");
  int n;
  fscanf(fin, "%d", &n);
  
  long int i, j, *R, *_R, msum = 0;
  R = calloc(1, sizeof(*R));

  for (i = 0; i < n; i++) {
    _R = calloc(i+2, sizeof(*_R));
    for (j= 0; j <=i; j++) {
      long int x; 
      fscanf(fin, "%ld", &x);
      *(R+j) += x;
      *(_R+j) = max(*(_R+j), *(R+j));
      *(_R+j+1) = max(*(_R+j+1), *(R+j));
      msum = max(msum, *(R+j));
    } 
    free(R);
    R = _R;
  } 
  fprintf(fout, "%ld\n", msum);

  return 0;
}
