/*
ID: ammar.q2
LANG: C
TASK: ride
*/
#include <stdio.h>

int f(char *line) {
	long int m = 1; 
	char *cur;
	for (cur = line; *cur != '\0'; cur ++) 
		m *= *cur - 'A' + 1;
	return m % 47;
}

main () {
    FILE *fin  = fopen ("ride.in", "r");
    FILE *fout = fopen ("ride.out", "w");
    char line[1000];
    fscanf (fin, "%s", line);	
    int a = f(line);
    fscanf (fin, "%s", line);
    int b = f(line);
    fprintf (fout, "%s\n", a == b? "GO" : "STAY");
    return 0;
}