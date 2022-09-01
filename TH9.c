#include <stdio.h>
#include <math.h>

int NT(int a){
	if (a <2) return 0;
	int i;
	for(i=2; i<=sqrt(a); i++)
		if(a%i==0)	return 0;
	return 1;
}
void Nhap(int a[][100], int m, int n){
	int i, j;
	for(i=0; i<m; i++){
		for(j=0; j<n; j++)
			scanf("%d", &a[i][j]);
	}
}

void Xuat(int a[][100], int m, int n){
	int i, j;
	for(i=0; i<m; i++){
		for(j=0; j<n; j++)
			printf("%3d |", a[i][j]);
		printf("\n");
	}
}
void inNT(int a[][100], int m, int n){
	int i, j;
	printf("\nSo nguyen to trong ma tran: ");
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			if (NT(a[i][j]) == 1) printf("%d ", a[i][j]);
}
int CP(int a){
	int i = sqrt(a);
	if (i*i == a) return 1;
	return 0;
}
void inCP(int a[][100], int m, int n){
	int i, j;
	printf("\nSo chinh phuong trong ma tran: ");
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			if (CP(a[i][j]) == 1) printf("%d ", a[i][j]);
}
void Max(int a[][100], int m, int n){
	int i, j, max = a[0][0];
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			max = (max > a[i][j]) ? max : a[i][j];
	printf("\nPhan tu max trong mang: %d", max);
}
void Min(int a[][100], int m, int n){
	int i, j, min = a[0][0];
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			min = (min < a[i][j]) ? min : a[i][j];
	printf("\nPhan tu min trong mang: %d", min);
	printf("\n");
}
void SapXep(int a[][100], int m, int n){
	int SL = m*n;
	int b[SL], i, j, x =0;
	for(i=0; i<m; i++)
		for(j=0; j<n; j++){
			b[x] = a[i][j];
			x++;
		}
	for(i=0; i<=x; i++)
		for(j=i+1; j<x; j++)
			if(b[i] > b[j]){
				int t = b[i];
				b[i] = b[j];
				b[j] = t;
			}
	for(i=0; i<x; i++){
		printf("%2d |", b[i]);
		if(i%n == n-1) printf("\n");
	}
}
int **Tich(float a[][100], int m, int n, float b[][100], int x, int y){
	int c[100][100];
	int i, j, x;
	for(i=0; i<m; i++)
		for(j=0; j<y; j++){
			c[i][j] = 0;
			for(x=0; x<n; x++)
				c[i][j] += a[i][x]*b[x][j];
		}
	return c;
	
}
int main(){
	int n, m; printf("Nhap m, n: "); 	scanf("%d%d", &m, &n);
	int a[100][100]; 	Nhap(a, m, n);
	Xuat(a, m, n);
	inNT(a, m ,n);
	inCP(a, m, n);
	Max(a, m, n);
	Min(a, m, n);
	SapXep(a, m, n);
	int c[100][100];
	int x, y; printf("Nhap x, y: "); 	scanf("%d%d", &x, &y);
	int a[100][100]; 	Nhap(a, m, n);
	c = Tich(a, m, n, b, x, y);
}
