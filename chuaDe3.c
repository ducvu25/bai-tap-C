
/*
Bai 5:
#include <stdio.h>

int main(){
	int n, i;
	printf("Nhap so luong phan tu: ");
	scanf("%d", &n);
	int a[n], b[n], c[n];	// mang b la chua duong, c chua am
	int x =0, y =0;
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
		if(a[i] > 0){
			b[x] = a[i];
			x++;
		}
		if(a[i] < 0){
			c[y] = a[i];
			y++;
		}
	}	
	printf("\nMang so duong: ");
	for(i=0; i<x; i++)
		printf("%d ", b[i]);
	printf("\nMang so am: ");
	for(i=0; i<y; i++)
		printf("%d ", c[i]);
}

#include<stdio.h>

int main(){
	int i,n;
	printf("so phan tu mang la n= ");
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		printf("phan tu a[%d] = ",i);
		scanf("%d",&a[i]);
    }
    printf("mang la \n");
	for(i=0;i<n;i++)
		printf(" %d \t",a[i]);
	printf("\n");
	int x=0,y=0;
	int duong[n];
	int am[n];
	for(i=0;i<n;i++){
		if(a[i]>0){
			duong[x]=a[i];
			x++;	
		}	
		if(a[i]<0){
			am[y]=a[i];
			y++;	
		}		
	}
	printf("mang am la\n ");
	for(i=0;i<y;i++)
		printf("%d\t ",am[i]);
	printf("\n");
	printf("mang duong la\n ");
	for(i=0;i<x;i++)
		printf("%d \t",duong[i]);
}
B3:

#include <stdio.h>

int main(){
	int n; 
	printf("Nhap vao n: ");
	scanf("%d", &n);
	if(n < 0)
		printf("n phai khong am.");
	else{
	
		int x, y, z, i;
		x = 0;
		y = 1;
		z = y + x;
//	if(n >= 0)
//		printf("%d ", x); // n =0
//	if(n >= 1)
//		printf("%d ", y); // n =1
		printf("\nKhong dung mang: ");
		for(i=0; i<=n; i++){
			if(i == 0)
				printf("0 ");
			else if(i == 1)
				printf("1 ");
			else{ //n >= 2
				printf("%d ", z);
				x = y;
				y = z;
				z = x + y;
			}
		}
	printf("\nDung mang: ");
	int a[n+1];
	a[0] = 0;
	a[1] = 1;
	for(i=0; i<=n; i++){
		if(i == 0)
			printf("0 ");
		else if(i == 1)
			printf("1 ");
		else{
			a[i] = a[i - 1] + a[i - 2];
			printf("%d ", a[i]);
		}
	}
	}
	
}
B6:

#include <stdio.h>

int main(){
	int n, i, j, k;
	printf("Nhap sl: ");
	scanf("%d", &n);
	int a[n]; 
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	
	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
			if(a[i] == a[j]){
				n--;
				for(k=j; k<n; k++)
					a[k] = a[k+1];
			}
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
}
B7:

#include <stdio.h>

int main(){
	int n, i, j, k;
	printf("Nhap sl: ");
	scanf("%d", &n);
	int a[n], b[n]; 
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	// a 5: 0 1 2 3 4
	// b 5: 4 3 2 1 0
	/* C1:
	for(i=0; i<n; i++)
		b[i] = a[n-1 - i];
	for(i=0; i<n; i++)
		a[i] = b[i];
	c2:
	for(i=0; i<=n/2; i++){
		int t = a[i];
		a[i] = a[n - 1 - i];
		a[n - 1 - i] = t;
	}
	for(i=0; i<n; i++)
		printf("%d ", a[i]);	
}
B8: 

#include <stdio.h>

int main(){
	int n, i, x, y;
	printf("Nhap sl: ");
	scanf("%d", &n);
	int a[n + 1]; 
	for(i=1; i<=n; i++)
		scanf("%d", &a[i]);
	// a 5: 0 1 2 3 4  
	// xoa phan tu thu x: 2 // 
//	printf("Nhap vi tri muon xoa: ");
//	scanf("%d", &x);
//	n--;
//	for(i=x; i<=n; i++)
//		a[i] = a[i+1];
//	for(i=1; i<=n; i++)
//		printf("%d ", a[i]);
	// chen the, vao vi tri x
	printf("Nhap gtri muon them: ");
	scanf("%d", &y);
	printf("Nhap vi tri muon them: ");
	scanf("%d", &x);
	n++;
	for(i=n; i> x; i--)
		a[i] = a[i-1];
	a[x] = y;// chen vao vi tri 3
	for(i=1; i<=n; i++)
		printf("%d ", a[i]);
}
B9:
*/
#include <stdio.h>

int main(){
	int n, m, i, x, y;
	printf("Nhap sl mang a: ");
	scanf("%d", &n);
	int a[n]; 
	for(i=1; i<=n; i++)
		scanf("%d", &a[i]);
	
	printf("Nhap sl mang b: ");
	scanf("%d", &m);
	int b[m]; 
	for(i=1; i<=m; i++)
		scanf("%d", &b[i]);
	int c[n + m];
	for(i=1; i<=n + m; i++)
		if(i <= n){
			c[i] = a[i];
		}else{
			c[i] = b[i - n];
		}
	for(i=1; i<=m + n; i++)
		printf("%d ", c[i]);
}
