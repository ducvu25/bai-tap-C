#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int ChuyenDoi(char *a){
	int gtri = 0, i;
	for(i=strlen(a)-1; i>=0; i--)
		gtri += (a[i] - 48)*pow(10, strlen(a) - 1 - i);
	return gtri;
}
int* HeSo(char *s, int *size){
	char x[100], y[100];
	int i, n, d, k;
	for(i=0; i<strlen(s); i++){
		if(s[i] == '^')
			d = i + 1;
		if(i == strlen(s)-1){
			strncpy(x, s + d, i - d -1);
			printf("%s", x);
			n = ChuyenDoi(x);
			break;
		}
		if(s[i] == ' '){
			strncpy(x, s + d, i - d);
			printf("%s", x);
			n = ChuyenDoi(x);
			break;
		}
	}
//	printf("%d", n);
//	*size = n;
//	int *a = (int*)malloc(n*sizeof(int));
//	for(i=0; i<n; i++)
//		a[i] = 0;
//		d = 0, k = 0;
//	for(i=0; i<strlen(s); i++){
//		if(s[i] == '*')
//			strncpy(y, s + d, i - d);
//		if(s[i] == '^')
//			k = i + 1;
//		if((s[i] == 32 && s[i+1] == '+') || i == strlen(s) - 1){
//			strncpy(x, s + k, i - k);
//			a[ChuyenDoi(x)] = ChuyenDoi(y);
//		}
//		if(s[i] == 32 && s[i-1] == '+')
//			d = i+1;
//	}
	return;
}
int main(){
	char a[100];
	int i, n;
	fgets(a, sizeof(a), stdin);
	int *A = HeSo(a, &n);
//	for(i=0; i<n; i++)
//		printf("%d ", A[i]);
//	int n;
//	scanf("%d", &n);
//	while(n > 0){
//		char a[10000];
//		char b[10000];
//		fflush(stdin);
//		fgets(a, sizeof(a), stdin);
//		fflush(stdin);
//		fgets(b, sizeof(b), stdin);
//		n--;
//	}
} 
