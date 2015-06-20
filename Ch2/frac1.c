/*
ID: ammar.q2
LANG: C
TASK: frac1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(int n1, int d1, int n2, int d2) {
  int t = n1*d2 - n2*d1;
  return (t == 0) ? 0 : (t / abs(t));
}

int main () {
  FILE *fin  = fopen ("frac1.in", "r");
  FILE *fout = fopen ("frac1.out", "w");
  int n, i, j;
  fscanf(fin, "%d", &n);

  int numfrac = 0;
  int nfrac[100000];
  int dfrac[100000];
  
  for (i = 1; i <= n; i++) {
    for (j = 0; j < i; j++) {
      nfrac[numfrac] = j;
      dfrac[numfrac] = i;
      int k = numfrac;
      numfrac++;
      while (k && (cmp(nfrac[k-1], dfrac[k-1], nfrac[k], dfrac[k]) > 0)) {
        nfrac[k-1] = nfrac[k-1] + nfrac[k];
        nfrac[k]   = nfrac[k-1] - nfrac[k];
        nfrac[k-1] = nfrac[k-1] - nfrac[k];
        dfrac[k-1] = dfrac[k-1] + dfrac[k];
        dfrac[k]   = dfrac[k-1] - dfrac[k];
        dfrac[k-1] = dfrac[k-1] - dfrac[k];
        k--;
      }
    }
  }  

  for (i = 0; i < numfrac; i++) {
    if (!i || cmp(nfrac[i-1], dfrac[i-1], nfrac[i], dfrac[i]) ) fprintf(fout, "%d/%d\n", nfrac[i],
      dfrac[i]);
  }

  fprintf(fout, "1/1\n");
  return 0;
}
