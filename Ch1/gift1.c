/*
ID: ammar.q2
LANG: C
TASK: gift1
*/
#include <stdio.h>
#include <string.h>

int find(char A[][1000], char *name){
	int i;
	for (i = 0; strcmp(*(A+i), name); i++);
	return i;
}

int main(){
	FILE *fin = fopen("gift1.in", "r");
	FILE *fout = fopen("gift1.out", "w");
	int n, i, j, giver, receiver, a, k;
	char names[1000][1000];
	int loss[1000];
	char line[1000];
	fscanf(fin, "%d", &n);

	for (i=0; i<n; i++) {
		fscanf(fin, "%s", names[i]); 
		loss[i] = 0;
	}
	for (i=0; i<n; i++) {
		fscanf(fin, "%s", line);
		giver = find(names, line);
		fscanf(fin, "%d %d", &a, &k);
                if (k) loss[giver] -= ((int) a/k)*k;
		for (j=0; j<k; j++) {
			fscanf(fin, "%s", line);
			receiver = find(names, line);
			loss[receiver] += (int) a/k;
		}
	}

	for (i=0; i<n; i++){
		fprintf(fout, "%s %d\n", names[i], loss[i]);
	}

	fclose(fin);
	fclose(fout);

	return 0;
}
