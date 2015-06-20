/*
ID: ammar.q2
LANG: C
TASK: castle
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int belongs_to[50][50];
int size[2500];
int num = 0;

int n, m;
int castle[50][50];

int max(int a, int b) {
  return a>b?a:b;
}

int in_range(int i, int j) {
  return 0 <= i && i <= n && 0 <= j && j <= m;
}

int adjacent(int i, int j, int a, int b) {
  return in_range(i, j) && in_range(a, b) && (abs(a-i) + abs(b-j) == 1);
}

int neighbour(int i, int j, int a, int b) {
  int shift = abs(a-i) * (a-i+2) + abs(b-j) * (b-j+1);
  return adjacent(i, j, a, b) && !((1<<shift) & castle[i][j]);
}


int main () {
  FILE *fin  = fopen ("castle.in", "r");
  FILE *fout = fopen ("castle.out", "w");
  int i, j, k, l;
  
  fscanf(fin, "%d %d", &m, &n);
  for (i=0; i<n; i++) {
    for (j=0; j<m; j++) {
      fscanf(fin, "%d", &castle[i][j]);
      belongs_to[i][j] = -1;
      size[i*n+j] = 0;
    }
  }

  int unassigned = n*m;
  int ux = 0, uy = 0;
  while (unassigned) {
    belongs_to[ux][uy] = num; 
    size[num]++;
    unassigned --;
    
    int x;
    do {
      x = 0;
      for (i=0; i<n; i++) {
        for (j=0; j<m; j++) {
          for (k=-1; k<2; k++) {
            for (l=-1; l<2; l++) {
              if (neighbour(i, j, i+k, j+l)){
                if ((belongs_to[i][j] == num) && (belongs_to[i+k][j+l] < 0)) {
                  x++;
                  belongs_to[i+k][j+l] = num;
                }
              }
            }
          }
        }
      }
      size[num] += x;
      unassigned -= x;
    } while (x);

    for (i=0; i<n; i++) 
      for (j=0; j<m; j++)
        if (belongs_to[i][j] == -1) {
          ux = i; uy = j;
        }
    num++;
  }

  fprintf(fout, "%d\n", num);

  int big = 0;
  for (i=0; i<num; i++) {
    big = max(big, size[i]); 
  } 

  fprintf(fout, "%d\n", big);
  
  int max = 0;
  int mx = 0, my = 0;
  char md = 'N';

  for (i=0;i<n;i++) {
    for (j=0;j<m;j++) {
      for (k=-1;k<1;k++) {
        for (l=-1;l<1;l++) {
          if (adjacent(i, j, i+k, j+l) && belongs_to[i][j] != belongs_to[i+k][j+l]) {
            int newroom = size[belongs_to[i][j]] + size[belongs_to[i+k][j+l]];
            if (newroom > max || (newroom == max && (j+l < my || (my == j+l && mx < i)))) {
              max = newroom;
              mx = i;
              my = j+l;
              md = (k==-1) ? 'N' : 'E';
            }
          }
        } 
      } 
    } 
  } 

  fprintf(fout, "%d\n", max);
  fprintf(fout, "%d %d %c\n", mx+1, my+1, md);
  return 0;
}
