/*
ID: ammar.q2
LANG: C
TASK: transform
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
void print(int *A, FILE *fout) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) 
      fprintf(fout, *(A+i*n+j)?"-":"@");
    fprintf(fout, "\n");
  }
}

int diff(int *A, int *B) {
  int i;
  for (i = 0; i < n*n; i++) 
    if (*(A+i) != *(B+i)) return 1;
  return 0;
}

int *copy(int *M) {
  int *_M = malloc(n*n*sizeof(*_M));
  memcpy(_M, M, n*n*sizeof(*_M));
  return _M;
}

int *reflect(int *M) {
  int i, j;
  int *T = copy(M);
  for (i = 0; i < n; i++) 
    for (j = 0; j < n; j++)
      *(T+i*n+j) = *(M+i*n + (n-j-1));
  return T;
}

int *rotate(int *M) {
  int i, j;
  int *T = copy(M);
  for (i = 0; i < n; i++) 
    for (j = 0; j < n; j++)   
      *(T+i*n+j) = *(M+j*n+(n-i-1));
  return T;
}

int *rotate_n(int *M, int x) {
  int i;
  int *T = M;
  for (i = 0; i < x; i++)
    T = rotate(T);
  return T;
}



int main () {
  FILE *fin  = fopen ("transform.in", "r");
  FILE *fout = fopen ("transform.out", "w");
    
  fscanf(fin, "%d", &n);

  int *M = malloc (n*n*sizeof(*M));
  int *T = malloc (n*n*sizeof(*T));
  
  char line[1000];
  int i, j; 
  for (i = 0; i < n; i++) {
    fscanf(fin, "%s", line);
    for (j = 0; j < n; j++) {
      *(M+i*n+j) = (line[j] == '-');
    }
  }
  for (i = 0; i < n; i++) {
    fscanf(fin, "%s", line);
    for (j = 0; j < n; j++) {
      *(T+i*n+j) = (line[j] == '-');
    }
  }

  if (!diff(T, rotate(M))) {
    fprintf(fout, "1\n");
  }
  else if (!diff(T, rotate_n(M, 2))) {
    fprintf(fout, "2\n");
  }
  else if (!diff(T, rotate_n(M, 3))) {
    fprintf(fout, "3\n");
  }
  else if (!diff(T, reflect(M))) {
    fprintf(fout, "4\n");
  }
  else if (!diff(T, rotate(reflect(M))) || !diff(T, rotate_n(reflect(M), 2)) || !diff(T, rotate_n(reflect(M), 3))) {
    fprintf(fout, "5\n");
  }
  else if (!diff(T, M)) {
    fprintf(fout, "6\n");
  }
  else {
    fprintf(fout, "7\n");
  }
  return 0;
}
