/*
1:

#include <stdio.h>

int main(){
	int n, i;
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	for(i=0; i<n; i++)
		printf("a[%d] = %d\n", i, a[i]);
}

2:

#include <stdio.h>

int main(){
	int n, i;
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
		
	int sum = 0, max = a[0], min = a[0], slPtDuong = 0;
	float Tb = 0;
	for(i=0; i<n; i++){
		sum += a[i];
		if(a[i] > 0){
			slPtDuong++;
			Tb += a[i];
		}
		if(max < a[i])
			max = a[i];
		if(min > a[i])
			min = a[i];
	}
	printf("\nTong cac phan tu trong mang: %d", sum);
	printf("\nTrung binh cong cua cac phan tu duong: %0.2f", Tb/slPtDuong);
	printf("\nMax = %d, min = %d", max, min);
}
3:

#include <stdio.h>

int main(){
	int n, i;
	printf("Nhap gtri n: ");
	scanf("%d", &n);
	
	printf("\na) ");
	int x = 0;
	int y = 1;
	if(n>=0)
		printf("%d ", x);
	if(n >=1)
		printf("%d ", y);
	int z;
	for(i=2; i<=n; i++){
		z = x + y;
		printf("%d ", z);
		x = y;
		y = z;
	}
	
	printf("\nb) ");
	int a[n];
	a[0] = 0;
	a[1] = 1;
	for(i=0; i<=n; i++){
		if(i <= 1)
			printf("%d ", a[i]);
		else{
			a[i] = a[i-1] + a[i-2];
			printf("%d ", a[i]);
		}
	}
}

4:

#include <stdio.h>

int main(){
	int n, i, j;
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
		
	printf("\nTruoc: \n");
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
			if(a[i] < a[j]){
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
	printf("\nSau: \n");
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
}

5:

#include <stdio.h>

int main(){
	int n, i;
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	
	int x =0, y = 0;
	int arrD[n], arrA[n];
	for(i=0; i<n; i++)
		if(a[i] > 0){
			arrD[x] = a[i];
			x++;
		}else if(a[i] < 0){
			arrA[y] = a[i];
			y++;
		}
	printf("\nMang ban dau: ");
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
	printf("\nMang duong: ");
	for(i=0; i<x; i++)
		printf("%d ", arrD[i]);
	printf("\nMang am: ");
	for(i=0; i<y; i++)
		printf("%d ", arrA[i]);
}

6:

#include <stdio.h>

int main(){
	int n, i, j, t;
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
		
	printf("\nMang ban dau: ");
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
		
	for(i=0; i<n - 1; i++)
		for(j=i+1; j<n; j++)
			if(a[i] == a[j]){
				n--;
				for(t=j; t<n; t++)
					a[t] = a[t+1];
				j--;
			}
	printf("\nMang sau: ");
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
}
7:

#include <stdio.h>

int main(){
	int n, i;
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	printf("\nMang ban dau: ");
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
	
	for(i=0; i<n/2; i++){
		int t = a[i];
		a[i]  = a[n - 1 - i];
		a[n - 1 - i] = t;
	}
	printf("\nMang sau: ");
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
}
8:

#include <stdio.h>

int main(){
	int n, i;
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	int a[n];
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	int x;
	printf("Nhap vi tri can xoa: "); 
	scanf("%d", &x);
	printf("\nMang ban dau: ");
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
	
	n--;
	for(i=x; i<n; i++)
		a[i] = a[i+1];
	printf("\nMang sau khi xoa: ");
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
	
}

9:

#include <stdio.h>

int main(){
	int m, n, i;
	printf("Nhap so luong phan tu mang a: ");
	scanf("%d", &m);
	int a[m];
	printf("Nhap mang a: ");
	for(i=0; i<m; i++)
		scanf("%d", &a[i]);
	
	printf("Nhap so luong phan tu mang b: ");
	scanf("%d", &n);
	int b[n];
	printf("Nhap mang b: ");
	for(i=0; i<n; i++)
		scanf("%d", &b[i]);
	
	int c[m+n];
	for(i=0; i<n+m; i++)
		if(i<n)
			c[i] = a[i];
		else
			c[i] = b[i - m];
	printf("\nMang a: ");
	for(i=0; i<m; i++)
		printf("%d ", a[i]);
	printf("\nMang b: ");
	for(i=0; i<n; i++)
		printf("%d ", b[i]);
	printf("\nMang c: ");
	for(i=0; i<m + n; i++)
		printf("%d ", c[i]);
}
10:
*/
#include <stdio.h>

int main(){
	int m, i;
	printf("Nhap so luong phan tu mang a: ");
	scanf("%d", &m);
	int a[m];
	printf("Nhap mang a: ");
	for(i=0; i<m; i++)
		scanf("%d", &a[i]);
	int x, y;
	printf("Nhap gri can chen va vi tri can chen: ");
	scanf("%d%d", &y, &x);
	
	printf("\nMang ban dau: ");
	for(i=0; i<m; i++)
		printf("%d ", a[i]);
	m++;
	for(i=m-1; i>x; i--)
		a[i] = a[i-1];
	a[x] = y;
	printf("\nMang sau: ");
	for(i=0; i<m; i++)
		printf("%d ", a[i]);
}
