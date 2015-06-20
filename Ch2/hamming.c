/*
ID: ammar.q2
LANG: C
TASK: hamming
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, b, d;
int valid[256][256];
int collection[256];
char out[1000] = "";
char toprint[1000] = "";

void reverse(char *s) {
  char *start = s, *end = s + strlen(s) - 1;
  while (start < end) {
    *start ^= *end;
    *end ^= *start;
    *start ^= *end;
    start++;
    end--;
  }
}

int neighbour(int x, int y) {
  int count = 0;
  while (x|y){
    count += (x&1) ^ (y&1);
    x >>= 1;
    y >>= 1;
  } 
  return count >= d;
}

int find(int collected, int current) {
  collection[current] = 1;
  if (collected == n) 
    return 1;
  int i, j;
  for (i = current+1; i < (1<<b); i++) {
    int x = 1;
    for (j = 0; j <= i; j++) {
      x &= !collection[j] || valid[i][j];
    }
    if (x) {
      if (find(collected+1, i)) {
        return 1;
      }
    }
  }
  collection[current] = 0;
  return 0;
}

int main () {
  FILE *fin  = fopen ("hamming.in", "r");
  FILE *fout = fopen ("hamming.out", "w");

  fscanf(fin, "%d %d %d", &n, &b, &d);
  
  int i, j; 
  for (i = 0; i < (1<<b); i++) {
    collection[i] = 0;
    for (j = i; j < (1<<b); j++) {
      valid[i][j] = valid[j][i] = neighbour(i, j);
    }
  }

  for (i = 0; i < (1<<b); i++) {
    if (find(1, i)) break;
  }
  
  j = 0;
  for (i = 0; i < (1<<b); i++) {
    if (collection[i]) {
      j++;
      sprintf(out, ((j%10 == 1) ? "%d" : " %d"), i);
      strcat(toprint, out);
      if (!(j%10)) strcat(toprint, "\n");
    }
  }
  if (j%10) strcat(toprint, "\n");
  fprintf(fout, "%s", toprint);
  return 0;
}
