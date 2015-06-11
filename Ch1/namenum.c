/*
ID: ammar.q2
LANG: C
TASK: namenum 
*/
#include <stdio.h>
#include <string.h>

char ctoi(char c) {
    return '2' + (c < 'Q' ? + (int)((c - 'A') / 3) : (int) ((c - 'A' - 1) / 3));
}

void apply(char *L) {
    int i;
    for (i = 0; L[i] != '\0'; i++) {
        L[i] = ctoi(L[i]);    
    }
}

int main () {
    FILE *fin  = fopen ("namenum.in", "r");
    FILE *fout = fopen ("namenum.out", "w");
    FILE *dict = fopen ("dict.txt", "r");
    char line[1000], num[1000], save[1000];
    fscanf (fin, "%s", num);	
    int count = 0;
    while (fscanf(dict, "%s", line)!=EOF) {
        sprintf(save, "%s", line);
        apply(line);
        if (!strcmp(num, line)) {
            fprintf(fout, "%s\n", save); 
            count++;
        }    
    }
    if (!count) {
        fprintf(fout, "NONE\n");
    }
    return 0;
}
