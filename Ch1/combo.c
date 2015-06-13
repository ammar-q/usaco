/*
ID: ammar.q2
LANG: C
TASK: combo
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int in_range(int l, int h, int e, int n) {
  if (e > h) e = e-n;
  if (e < l) e = e+n;
  return (l <= e && e<= h);
}

int close_to(int n, int A[], int B[]) {
  int i;
  for (i = 0; i < 3; i++) {
    if (!in_range( A[i]-2, A[i]+2, B[i], n)) {
      return 0;
    }
  }
  return 1;
}

int main () {
  FILE *fin  = fopen ("combo.in", "r");
  FILE *fout = fopen ("combo.out", "w");
  int n;
  fscanf(fin, "%d", &n);
  int f[3];
  int m[3];
  fscanf(fin, "%d %d %d", &f[0], &f[1], &f[2]);
  fscanf(fin, "%d %d %d", &m[0], &m[1], &m[2]);
  int count = 0;

  int i, j, k;
  for (i=1; i<=n; i++)
    for (j=1; j<=n; j++)
      for (k=1; k<=n; k++) {
        int c[3] = {i, j, k};
        if (close_to(n, f, c) || close_to(n, m, c)) 
          count++;
      }

  fprintf(fout, "%d\n", count);
  return 0;
}
