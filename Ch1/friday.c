/*
ID: ammar.q2
LANG: C
TASK: friday
*/
#include <stdio.h>

int days[7] = {0,0,0,0,0,0,0};
int month[12] = {31,31,28,31,30,31,30,31,31,30,31,30};

int leap(n, m) {
  int y = 1900+n;
  return !!(m == 2 && (!(y%400)||(!(y%4)&&(y%100))) );
}

void travel(n) {
  int i, j, d = 5;
  for (i = 0; i < n; i++) {
    for (j = 0; j < 12; j++){
      days[((d=(d+month[j]+leap(i,j))%7)+13)%7]+=1; 
    }
  }
}

int main () {
  FILE *fin  = fopen ("friday.in", "r");
  FILE *fout = fopen ("friday.out", "w");
  int n, i;
  fscanf (fin, "%d", &n);
  travel(n);
  for (i = 0; i < 7; i++){
    fprintf(fout, i!=6?"%d ":"%d", days[i]);
  }
  fprintf(fout, "\n");
  return 0;
}
