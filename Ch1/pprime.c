/*
ID: ammar.q2
LANG: C
TASK: pprime
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long int primes[10000], numprimes = 0;
long int pals[1000000], numpals = 0;
long int a, b;
FILE *fin; 
FILE *fout; 

int is_prime(long int i) {
  int j, p = 1;
  if (i < 5) return 0;
  for (j = 0; j < numprimes; j++) {
    if (primes[j] > sqrt(i) ) break;
    if (i %primes[j] == 0) { p = 0; break; }
  } 
  return p;
}

void pal(long int p, int n, int o) {
  if (!n) {
    long int x = o ? p / 10 : p;
    while (p) {
      x = x * 10 + p % 10;
      p = p / 10;
    }
    if (is_prime(x) && x <= b && x >= a) fprintf(fout, "%ld\n", x);
  }
  else {
    int i;
    for (i = 0; i < 10; i++) {
      pal(p*10+i, n-1, o);
    }
  }
}

int main () {
  fin  = fopen ("pprime.in", "r");
  fout = fopen ("pprime.out", "w");
  fscanf(fin, "%ld %ld", &a, &b);
  
  long int i, j;

  primes[0] = 2; 
  numprimes ++;
  
  for (i = 3; i <= 10000; i += 2) {
    int p = 1;
    for (j = 0; j < numprimes; j++) {
      if (primes[j] > sqrt(i)) break;
      if (i % primes[j] == 0) {
        p = 0;
        break;
      }
    }
    if (p) {
      primes[numprimes] = i;
      numprimes++;
    }
  }

  for (i = 1; i < 9; i ++) {
    for (j = 1; j < 10; j++) {
      pal(j, (i-1)/2,i%2);
    }
  }
  return 0;
}
