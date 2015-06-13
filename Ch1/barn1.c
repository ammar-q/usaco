/*
ID: ammar.q2
LANG: C
TASK: barn1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int sum(long int *A, long int k) {
  long int i, a = 0;
  for (i = 0; i < k; i++)
    a += *(A+i);
  return a;
}

void swap(long int *a, long int *b) {
  *a = *a + *b;
  *b = *a - *b;
  *a = *a - *b;
}

void sort(long int *A, long int n) {
  long int i, j;
  for (i = 0; i < n; i++) 
    for (j = 0; j < n-1; j++)
      if (*(A+j) < *(A+j+1)) 
        swap(A+j, A+j+1);
}

long int *diff(long int *A, long int n) {
  long int *D = malloc((n-1)*sizeof(*D));
  long int i;
  for (i = 0; i < n-1; i++) {
    *(D+i) = *(A+i) - *(A+i+1) - 1;
  }
  sort(D, n-1);
  return D;
}


int main () {
  FILE *fin  = fopen ("barn1.in", "r");
  FILE *fout = fopen ("barn1.out", "w");
  long int m, s, n;
  fscanf(fin, "%ld %ld %ld", &m, &s, &n);
  long int mincow = 200, maxcow = 0;
  long int *A = malloc(n*sizeof(*A));
  
  long int i;
  for (i = 0; i < n; i++) {
    fscanf(fin, "%ld", A+i);
    if (*(A+i) > maxcow) maxcow = *(A+i);
    if (*(A+i) < mincow) mincow = *(A+i);
  }
  sort(A, n);
  long int covered = maxcow - mincow + 1 - sum(diff(A, n), (m-1 < n) ? m-1 : n-1);
  fprintf(fout, "%ld\n", covered);
  return 0;
}
