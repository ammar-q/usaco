/*
ID: ammar.q2
LANG: C
TASK: sprime
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

long int primes[10000], numprimes = 0;

int is_prime(long int i) {
  int j, p = 1;
  for (j = 0; j < numprimes; j++) {
    if (primes[j] > sqrt(i) ) break;
    if (i %primes[j] == 0) { p = 0; break; }
  } 
  return i-1? p : 0;
}

void sprime(long int p, int n, FILE *fout) {
  if (n == 0) fprintf(fout, "%ld\n", p);
  else {
    long int x = p*10;
    int i;
    for (i = 1; i < 10; i++) {
      if (is_prime(x+i)) sprime(x+i, n-1, fout);
    }
  }
}

int main () {
  FILE *fout = fopen ("sprime.out", "w");
  FILE *fin  = fopen ("sprime.in", "r");
  int n;
  fscanf(fin, "%d", &n);
  
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

  
  sprime(0, n, fout);
  return 0;
}
