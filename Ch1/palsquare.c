/*
ID: ammar.q2
LANG: C
TASK: palsquare
*/
#include <stdio.h>
#include <stdlib.h>

struct digitslist {
  int digit;
  struct digitslist *next;
};

struct digitslist *copydigit(struct digitslist *D) {
    struct digitslist *C = malloc(sizeof(*C));
    C->digit = D->digit; 
    return C;
}

struct digitslist *reverse(struct digitslist *L) {
    struct digitslist *R = NULL;
    struct digitslist *cur;
    for (cur = L; cur; cur = cur->next) {
        struct digitslist *D = copydigit(cur);
        D->next = R;
        R = D;
    }
    return R;
}

int comp(struct digitslist *A, struct digitslist *B) {
    struct digitslist *curA, *curB;
    for (curA=A,curB=B; curA && curB; curA=curA->next, curB=curB->next){
      if (curA->digit != curB->digit) return 0;
    }
    return 1;
}

int palindrome(struct digitslist *L) {
    return comp(L, reverse(L));
}

void print(FILE *fout, struct digitslist *n) {
    struct digitslist *cur;
    for (cur = n; cur; cur=cur->next) {
        fprintf(fout, "%c", cur->digit + ((cur->digit < 10)? '0': 'A'-10) );
    }
}

struct digitslist *attach_to_end(struct digitslist *L, struct digitslist *D) {
    struct digitslist *cur;
    for (cur = L; cur->next; cur=cur->next);
    cur->next = D;
    return L;
}

struct digitslist *to_base(int b, int i) {
    struct digitslist *d = malloc(sizeof(struct digitslist *));
    d->digit = i % b;
    d->next = NULL;
    return ((int)i/b) ? attach_to_end(to_base(b, (int) i / b), d) : d;
}

int main () {
    FILE *fin  = fopen ("palsquare.in", "r");
    FILE *fout = fopen ("palsquare.out", "w");
    int b;
    fscanf (fin, "%d", &b);	
    int i; for (i = 1; i <= 300; i++) {
        struct digitslist *n    = to_base(b, i);
        struct digitslist *n_sq = to_base(b, i*i);
        if (palindrome(n_sq)){ 
            print(fout, n);
            fprintf(fout, " ");
            print(fout, n_sq);
            fprintf(fout, "\n");
        }
    }
    return 0;
}
