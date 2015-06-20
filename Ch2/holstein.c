/*
ID: ammar.q2
LANG: C
TASK: holstein
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int minimum = 16;
int minlist = 0;
int requirements[25];
int scoop[15][25];
int v, g;


int valid() {
  int i, x = 1;
  for (i=0; i<v; i++) {
    x &= (requirements[i] <= 0);
  }  
  return x;
}

void update(int x, int d) {
  int i;
  for (i=0; i<v; i++) {
    requirements[i] += d*scoop[x][i];
  }
}

void find(int cur, int min, int list){
  if (cur == g) {
    if (valid() && (minimum > min || (minimum == min && list < minlist))) {
      minimum = min;
      minlist = list;
    }
  }
  else {
    update(cur, -1);
    find(cur+1, min+1, list | (1 << cur));
    update(cur, 1);
    find(cur+1, min, list);
  }
}



int main () {
  FILE *fin  = fopen ("holstein.in", "r");
  FILE *fout = fopen ("holstein.out", "w");
  fscanf(fin, "%d", &v);
  int i, j;
  for (i=0; i<v; i++) 
    fscanf(fin, "%d", &requirements[i]);
  fscanf(fin, "%d", &g);
  for (i=0; i<g; i++) {
    for (j=0; j<v; j++) {
      fscanf(fin, "%d", &scoop[i][j]); 
    } 
  }  
  find(0, 0, 0);
  
  fprintf(fout, "%d ", minimum);
  
  i = 0;
  while (minlist) {
    i++;
    if (minlist & 1) {
      fprintf(fout, "%d", i);
      fprintf(fout, (minlist & ~1) ? " " : "\n");
    }
    minlist >>= 1;
  }
  return 0;
}
