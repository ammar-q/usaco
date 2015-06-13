/*
ID: ammar.q2
LANG: C
TASK: skidesign
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int min (long int a, long int b) {
  return a < b ? a : b;
}

long int max (long int a, long int b) {
  return a > b ? a : b;
}

long int change(int k, int hill[], int n) {
  int i;
  long int sum = 0;
  for (i = 0; i < n; i++) {
    long int delta = (max(abs(hill[i] - k), abs(k+17 - hill[i])) > 17) ? min(abs(hill[i] - k), abs(k+17 - hill[i])): 0; 
    sum += delta * delta;
  }
  return sum;
}


int main () {
  FILE *fin  = fopen ("skidesign.in", "r");
  FILE *fout = fopen ("skidesign.out", "w");
  int hill[1000];
  int n;

  fscanf(fin, "%d", &n);
  int i;
  for (i = 0; i < n; i++) {
    fscanf(fin, "%d", &hill[i]);
  }
  
  long int m = 2000000;
  for (i = 0; i < 100; i++) {
    m = min(m, change(i, hill, n));
  }

  fprintf(fout, "%ld\n", m);
  return 0;
}
