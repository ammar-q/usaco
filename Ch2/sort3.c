/*
ID: ammar.q2
LANG: C
TASK: sort3
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int places[3] = {0, 0, 0};
int list[100000];
int from_at[3][3];
int n;

int min(a, b) {
  return a < b ? a : b;
}

int finish() {
  int moves = 0;
  int i, j;
  for (i=0; i<3; i++){
    for (j=0; j<3; j++) {
      if (j != i) {
        int diff = min(from_at[i][j], from_at[j][i]);
        from_at[i][j] -= diff;
        from_at[j][i] -= diff;
        from_at[i][i] += diff;
        from_at[j][j] += diff;
        moves += diff;
      }
    }
  }
  return moves;
}

int main () {
  FILE *fin  = fopen ("sort3.in", "r");
  FILE *fout = fopen ("sort3.out", "w");
  fscanf(fin, "%d", &n);

  int i, j, k, l;
  for (i = 0; i < n; i++) {
    fscanf(fin, "%d", &list[i]);
    list[i] --;
    places[list[i]] ++;
  }

  for (i=0; i<3; i++){
    places[i] += i ? places[i-1] : 0;
    for (j = 0; j < 3; j++)
      from_at[i][j] = 0;
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < 3 && i >= places[j]; j++);
    from_at[list[i]][j] ++;
  }

//  for (i = 0; i < 3; i++) printf("places: %d\n", places[i]);

//  for (i = 0; i < 3; i++) {
//    for (j = 0; j < 3; j++) {
//      printf ("%d ", from_at[i][j]);
//    }
//    printf ("\n");
//  }

  int moves = 0;
  while (from_at[1][1]+from_at[2][2]+from_at[0][0] < n) {
//    for (i = 0; i < 3; i++) {
//      for (j = 0; j < 3; j++) {
//        printf ("%d ", from_at[i][j]);
//      }
//      printf ("\n");
//    }
  
    moves += finish();

    for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
        for (k = 0; k < 3; k++) {
          if (i != j && k != i && k != j) {
            int diff = min(from_at[i][j], from_at[k][i]);
            from_at[i][j] -= diff;
            from_at[k][i] -= diff;
            from_at[i][i] += diff;
            from_at[k][j] += diff;
            moves += diff;
          }
          moves += finish();
        }
      }
    }
  }

  fprintf(fout, "%d\n", moves);
  return 0;
}
