/*
ID: ammar.q2
LANG: C
TASK: wormhole
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct wormhole {
  long int x;
  long int y;
  struct wormhole *portal;
  int follow;
} Wormhole;

Wormhole W[12];

int F(int i, char f) {
  static int s = 0;
  if (f == 's')
    s |= 1 << i;
  else if (f == 'u')
    s &= ~(1 << i);
  else {
    return (s >> i) & 1;
  }
  return 0;
}

int set(int i) {
  return F(i, 's');
}

int unset(int i) {
  return F(i, 'u');
}

int is_set(int i) {
  return F(i, 'r');
}

int from_node(int k) {
  if (W[k].portal->follow >= 0) {
    if (is_set(k)) {
      return 1;
    } else {
      set(k);
      int x = from_node(W[k].portal->follow);
      unset(k);
      return x;
    }
  }
  return 0;
}

long int try_all(int k, int n) {
  int i, j;
  if (k == n) {
    for (i = 0; i < n; i++) {
      if (from_node(i)) return 1;
    }
    return 0;
  } else {
    if (W[k].portal){
      return try_all(k+1, n);
    }
    else {
      long int s = 0;
      for (i = k+1; i < n; i++) {
        if (!W[i].portal) {
          W[k].portal = &W[i];
          W[i].portal = &W[k];
          s += try_all(k+1, n);
          W[k].portal = NULL;
          W[i].portal = NULL;
        }
      }
      return s;
    }

  }
}


int main () {
  FILE *fin  = fopen ("wormhole.in", "r");
  FILE *fout = fopen ("wormhole.out", "w");
  
  int n;
  fscanf(fin, "%d", &n);

  int i, j;

  for (i = 0; i < n; i++) {
    fscanf(fin, "%ld %ld", &W[i].x, &W[i].y);
    W[i].follow = -1;
    W[i].portal = NULL;
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (W[i].y == W[j].y && W[i].x > W[j].x) {
        W[j].follow = (W[j].follow >= 0 && W[W[j].follow].x < W[i].x)?  W[j].follow : i;
      } 
    }      
  }

  fprintf(fout, "%ld\n", try_all(0 , n));

  return 0;
}
