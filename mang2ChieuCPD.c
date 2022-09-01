#include <stdio.h>
#include <stdlib.h>

int** Nhap(int m, int n){
	int **a;
	int i, j;
	a = malloc(sizeof(int*)*m);
	for(i=0; i<m; i++)
		a[i] = malloc(sizeof(int)*n);
			
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			scanf("%d", &a[i][j]);
	return a;
}
void Xuat(int **a, int m, int n){
	int i, j;
	for(i=0; i<m; i++){
		for(j=0; j<n; j++)
			printf("%d \t", a[i][j]);
		printf("\n");
	}
}
void yA(int **a, int m, int n){
	int i, j;
	int min = a[0][0];
	for(j = 0; j <n; j+=2)
		for(i=0; i<m; i++)
			if(min > a[i][j])
				min = a[i][j];
	printf("Gia tri nho nhat cua cac phan tu tren cot le la: %d\n", min);
}
void yB(int **a, int m, int n){
	long Tich = 1;
	int i, j;
	for(i = 0; i<m; i++)
		for(j=0; j<n; j++)
			if(a[i][j] % 5 == 0)
				Tich *= a[i][j];
	printf("Tich cac phan tu trong mang chia het cho 5 la: %ld", Tich);
}

int main(){
	int m, n;
	scanf("%d%d", &m, &n);
	int **a = Nhap(m, n);
	Xuat(a, m, n);
	yA(a, m, n);
	yB(a, m, n);
}
