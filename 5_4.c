#include <stdio.h>

int main(){
	int n;
	int a[100][100];
	int k, i, j;
	printf("\nNhap n: ");
	scanf("%d", &n);
	printf("Nhap ma tran nxn:\n");
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%d", &a[i][j]);
	printf("Ma tran vua nhap:\n");
	for(i=0; i<n; i++){
		for(j=0; j<n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	printf("Cac phan tu chan trong ma tran: ");
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if(a[i][j] %2 == 0)
				printf("%d ", a[i][j]);

	int sum = 0;
	for(i=0; i<n; i++)
		sum += a[i][i];
	printf("\nTong cac pt tren duong cheo chinh: %d", sum);
 	return 0;
}
