
#include <stdio.h>
#include <string.h>
void Q1(char *a){
	int i;
	char s[1000];
	strcpy(s, a);
	for(i=0; i<strlen(s); i++)
		if(s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
	printf("\nChuoi in thuong \t = %s", s);
	for(i=0; i<strlen(s); i++)
		if(s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
	printf("CHUOI IN HOA \t\t = %s", s);
	for(i=0; i<strlen(s); i++)
		if(i > 0 && s[i-1] != 32 && s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
	printf("Chuoi In Hoa Kt Dau \t = %s", s);
}
void Q2(char *s){
	char a[1000];
	strcpy(a, s);
	int i, j;
	for(i=0; i<strlen(s)-2; i++)
		for(j=i+1; j<strlen(a)-1; j++)
			if(a[i] > a[j]){
				char t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
	printf("Sau khi sap xep:\n %s\n", a);
}
void Q3(char *s, char t){
	char a[1000];
	strcpy(a, s);
	int i;
	for(i=0; i<strlen(a); i++)
		if(a[i] == 32 || i == strlen(a) -1)
			a[i] = t;
	printf("Chuoi sau khi thay the: %s", a);
}
void Q4(char *s){
	int A[150] = {0};
	int i;
	char a[1000];
	strcpy(a, s);
	for(i=0; i<strlen(a)-1; i++)
		A[a[i]] ++;
	printf("Tan so:\n");
	for(i=0; i<strlen(a)-1; i++)
		if(A[a[i]] != 0){
			printf("%c \t %d\n", a[i], A[a[i]]);
			A[a[i]] = 0;
		}
}
void BSort(char Name[][100], int n){
	int i, j;
	for(i=n-1; i>0; i--){
		int d = 1;
		for(j=0; j<i; j++)
			if(strcmp(Name[j],Name[j+1]) > 0){
				char t[100];
				strcpy(t, Name[j]);
				strcpy(Name[j], Name[j+1]);
				strcpy(Name[j+1], t);
				d = 0;
			}
		if(d) break;
	}
}
int main(){
	int k;
	do{
		
		printf("\n\t\tMenu");
		printf("\n\t1. Chuc Nang 1");
		printf("\n\t2. Chuc Nang 2");
		printf("\n\t0. Thoat");
		printf("\n\tChuc nang: ");
		scanf("%d", &k);
		switch(k){
			case 1:{
				char s[1000];
				fflush(stdin);
				printf("Nhap chuoi: ");
				fgets(s, sizeof(s), stdin);
				Q1(s);
				Q2(s);
				char c;
				fflush(stdin);
				printf("Nhap ki tu thay the: ");
				scanf("%c", &c);
				Q3(s, c);
				
				Q4(s);
				break;
			}
			case 2:{
				int n, i;
				printf("Nhap n: ");
				scanf("%d", &n);
				char Name[100][100];
				for(i=0; i<n; i++){
					printf("Nhap ten: ");
					scanf("%s", Name[i]);
				}
				BSort(Name, n);
				for(i=0; i<n; i++)
				printf("%s\n", Name[i]);
				break;
			}
			case 0:{
				printf("\tKet thuc");
				break;
			}
		}
	}while(k != 0);

}
