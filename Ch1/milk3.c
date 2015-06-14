/*
ID: ammar.q2
LANG: C
TASK: milk3
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int state_visited[21][21][21];
int print_state[21];
int a_cap, b_cap, c_cap;

int min(int a, int b) {
  return a < b ? a : b;
}

int pour(int amt1, int amt2, int cap2 ) {
  return min(amt1, cap2-amt2);
}

void visit(int a, int b, int c) {
  if (state_visited[a][b][c]) return;
  state_visited[a][b][c] = 1;
  print_state[c] |= (a == 0);
  
  visit(a-pour(a, b, b_cap), b+pour(a, b, b_cap) , c);
  visit(a-pour(a, c, c_cap), b, c+pour(a, c, c_cap));
  visit(a+pour(b, a, a_cap), b-pour(b, a, a_cap) , c);
  visit(a, b-pour(b, c, c_cap) , c+pour(b, c, c_cap));
  visit(a+pour(c, a, a_cap), b, c-pour(c, a, a_cap) );
  visit(a, b+pour(c, b, b_cap) , c-pour(c, b, b_cap));
}

int main () {
  FILE *fin  = fopen ("milk3.in", "r");
  FILE *fout = fopen ("milk3.out", "w");
  
  fscanf(fin, "%d %d %d", &a_cap, &b_cap, &c_cap);

  int *out = malloc(21*sizeof(*out));
  int i, j, k;
  for (i = 0; i < 21; i++) {
    print_state[i] = 0;
    *(out+i) = 0;
    for (j = 0; j < 21; j++)
      for (k = 0; k < 21; k++)
        state_visited[i][j][k] = 0;
  }

  visit(0, 0, c_cap);

  int count = 0;
  for (i = 0; i < 21; i ++) {
    if (print_state[i]) out[count++] = i;
  }
  
  for (i = 0; i < count; i++) {
    fprintf(fout, "%d%s", out[i], (out[i+1] == 0)? "\n" : " ");
  }

  return 0;
}
