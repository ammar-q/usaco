/*
ID: ammar.q2
LANG: C
TASK: ariprog
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *B;

int follow(int i, int j, int n) {
  if (!B[i]) return 0;
  return (n == 0) ? 1 : follow(i+j, j, n-1);
}


int main () {
  FILE *fin  = fopen ("ariprog.in", "r");
  FILE *fout = fopen ("ariprog.out", "w");
  B = calloc(200000, sizeof(*B));
  
  int n, m;
  fscanf(fin, "%d", &n);
  fscanf(fin, "%d", &m);

  int i, j;
  for (i = 0; i <= m; i ++) 
    for (j = i; j <= m; j ++) 
      *(B+i*i+j*j) = 1;


  int c = 0;
  for (j = 1; j <= 2*m*m; j++) {
    for (i = 0; i <= 2*m*m - j*(n-1) + 1; i++) {
      if (follow(i, j, n-1)) {
        c++;
        fprintf(fout, "%d %d\n", i, j);
      }
    }
  }

  if (!c) {
    fprintf(fout, "NONE\n");
  }

  return 0;
}
