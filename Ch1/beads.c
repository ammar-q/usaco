/*
ID: ammar.q2
LANG: C
TASK: beads
*/
#include <stdio.h>
int beads[700];
int blue = 0, red = 0;

void calculate(int profit[][700], int k, int n) {
  int start = (n - 1 + k) % n;
  int step = 2 * k - 1;
  int i, r = 0, c = beads[start], w = 0;
  for (i=start; k?(i < n):(i > -1); i=i+step) {
    if (c == 0) c = beads[i];
    if (beads[i] && beads[i] != c) {c = beads[i]; r = 1+w;}
    else r = r + 1; 
    w = (beads[i])?0:w+1;
    profit[k][i] = r;
  }
}

void transcribe(int *beads, char *line, int s) {
  int i;
  for (i = 0; line[i] != '\0'; i++) {
    beads[s+i] = (line[i] != 'w')?((line[i] == 'r')?1:-1):0;
    blue |= (beads[s+i] == -1);
    red |= (beads[s+i] == 1);
  }
}

int main () {
  FILE *fin  = fopen ("beads.in", "r");
  FILE *fout = fopen ("beads.out", "w");
  int n;
  char line[1000];
  fscanf (fin, "%d", &n); 
  fscanf (fin, "%s", line); 
  transcribe(beads, line, 0);
  transcribe(beads, line, n);
  int profit[2][700];
  calculate(profit, 1, 2*n);
  calculate(profit, 0, 2*n);
  int i, max = 0;
  for (i = 0; i < 2*n - 1; i++){
    if (profit[1][i] + profit[0][i+1] > max) {
      max = profit[1][i] + profit[0][i+1]; 
    }
  }
  max = blue*red? max : n;
  max = max > n ? n : max;
  fprintf(fout, "%d\n", max);
  return 0;
}
