/*
ID: ammar.q2
LANG: C
TASK: crypt1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void add(int *set, int digit) {
  *set |= 1 << digit;  
}

int included(int set, int digit) {
  return set & 1 << digit;
}

int valid(int X, int length, int set) {
  while (length) {
    if (!included(set, X%10)) 
      return 0;
    X = X/10;
    length --;
  }
  return !X;
}


int test_all(int set) {
  int i, j, r = 0;
  for (i = 100; i < 1000; i++) {
    if (valid(i, 3, set)) {
      for (j = 10; j < 100; j++) {
        if (valid(j, 2, set)) {
          if (
              valid(i*(j%10), 3, set) && 
              valid(i*(j/10), 3, set) && 
              valid(     i*j, 4, set)
             ) {
              r++;
          }
        }
      }
    }
  }
  return r;
}


int main () {
  FILE *fin  = fopen ("crypt1.in", "r");
  FILE *fout = fopen ("crypt1.out", "w");

  int set = 0;
  int n, d, i;
  fscanf(fin, "%d", &n);

  for (i = 0; i < n; i++) {
    fscanf(fin, "%d", &d);
    add(&set, d);
  }
  
  fprintf(fout, "%d\n", test_all(set));

  return 0;
}
