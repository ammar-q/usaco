/*
ID: ammar.q2
LANG: C
TASK: milk2
*/
#include <stdio.h>
#include <stdlib.h>

struct interval{
  long int x;
  long int y;
  struct interval *next;
};

void merge_in_front(struct interval *H);
void add(struct interval *H, struct interval *X);
void freelist(struct interval *A);
long int max (long int a, long int b);
long int fnmax(struct interval *A, long int (*f)(struct interval *));
long int inside (struct interval *A);
long int between(struct interval *A); 

void merge_in_front(struct interval *H) {
  while (H->next && H->next->x <= H->y) {
    H->y = max(H->y, H->next->y);
    struct interval *tmp = H->next;
    H->next = H->next->next;
    free(tmp);
  }
}

void add(struct interval *H, struct interval *X){
  if (H->x <= X->x && (!(H->next) || X->x <= H->next->x)){
    X->next = H->next;
    H->next = X;
    if (X->x <= H->y) {
      merge_in_front(H);
    } else {
      merge_in_front(X);
    }
  }
  else add(H->next, X);
}

void freelist(struct interval *A) {
  if (A) {
    freelist(A->next);
    free(A);
  }
}

long int max (long int a, long int b) {
  return a>b ? a : b;
}

long int fnmax(struct interval *A, long int (*f)(struct interval *)) {
  if (A) {
    return (A->x + A->y)? max(f(A), fnmax(A->next, f)) : fnmax(A->next, f);
  } else {
    return 0;
  }
}

long int inside (struct interval *A) {
  return A ? A->y - A->x : 0;
}

long int between(struct interval *A) {
  return A ? (A->next ? A->next->x - A->y : 0) : 0;
}

int main () {
  FILE *fin  = fopen ("milk2.in", "r");
  FILE *fout = fopen ("milk2.out", "w");
  long int n, a, b;
  fscanf (fin, "%ld", &n);

  struct interval *top = malloc(sizeof(*top));
  top->next = NULL;
  top->x  = 0;
  top->y  = 0;

  struct interval *X;
  int i; for (i = 0; i < n; i++){
    fscanf (fin, "%ld %ld", &a, &b);
    X = malloc(sizeof(*X));
    X->next = NULL;
    X->x  = a;
    X->y  = b;
    add(top, X);
  }
  
  fprintf (fout, "%ld %ld\n", fnmax(top, inside), fnmax(top, between));
  return 0;
}
