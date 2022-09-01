#include <stdio.h>

int main(){
	FILE *input;
	input = fopen("Cau2.inp", "r");
	int n, i, x = 0;
	fscanf(input, "%d", &n);
	long a[n];
	for(i=0; i<n; i++)
		fscanf(input, "%ld", &a[i]);
	long max = a[0];
	for(i=1; i<n; i++)
		if(max < a[i]){
			max = a[i];
			x = i;
		}
	FILE *out;
	out = fopen("Cau2.out", "w");
	fprintf(out, "%ld\n%d", max, x + 1);
	
}
