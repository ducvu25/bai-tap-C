/*4.1 Nhap vao so n, va mang a, tim min, max trong mang

#include <stdio.h>
 
  typedef struct{
  	int gtri;
  	int vtri;
  }arr;
 void Nhap(arr *a, int n){
 	int i;
 	for(i=0; i<n; i++){
 		printf("Nhap gia tri a[%d]: ", i);
 		a[i].vtri = i;
 		scanf("%d", &a[i].gtri);
	 }
 }
 
 arr Max(arr *a, int n){
 	int i;
	arr max = a[0];
 	for(i=1; i<n; i++)
 		max = (max.gtri > a[i].gtri) ? max : a[i];
 	return max;
 }
 
 arr Min(arr *a, int n){
 	int i;
	arr max = a[0];
 	for(i=1; i<n; i++)
 		max = (max.gtri < a[i].gtri) ? max : a[i];
 	return max;
 }
 
 void Swap(arr *a, int n, arr x, arr y){
 	arr t;
	 t = a[x.vtri];
 	a[x.vtri] = a[y.vtri];
 	a[y.vtri] = t;
 }
 void Xuat(arr *a, int n){
 	int i;
 	for(i=0; i<n; i++)
 		printf("%d ", a[i].gtri);
 	printf("\n");
 }
 int main(){
 	int n; printf("Nhap so luong pt: "); 	scanf("%d", &n);
 	arr a[n];	Nhap(a, n);
 	Xuat(a, n);
 	printf("Max = %d\nMin = %d\n", Max(a, n).gtri, Min(a, n).gtri);
 	Swap(a, n, Max(a, n), Min(a, n));
 	Xuat(a, n);
 	
 }
 */
 
 /* 4.2 Nhap mang gom n pt roi tim ra so lon t2 va nho t2
 
 #include <stdio.h>
 
 void Nhap(int *a, int n){
 	int i;
 	for(i=0; i<n; i++){
 		printf("Nhap gtri a[%d]: ", i);
 		scanf("%d", &a[i]);
	 }
 }
 void Xuat(int *a, int n){
 	int i;
 	printf("\nMang a:\n");
 	for(i=0; i<n; i++)
 		printf("%d ", a[i]);
 	printf("\n");
 }
 int Max2(int *a, int n){
 	int max1 = a[0], max2, i;
	for(i=1; i<n; i++)
		if(max1 < a[i]) {
			max2 = max1;
			max1 = a[i];
		}  
	return max2;
 }
 int Min2(int *a, int n){
 	int max1 = a[0], max2, i;
	for(i=1; i<n; i++)
		if(max1 > a[i]) {
			max2 = max1;
			max1 = a[i];
		}  
	return max2;
 }
 int main(){
 	int n;	printf("Nhap so luong phan tu: ");	scanf("%d", &n);
 	int a[n]; printf("Nhap mang:\n");	Nhap(a, n);
 	printf("Phan tu lon thu 2 trong mang la: %d\n", Max2(a, n));
 	printf("Phan tu be thu 2 trong mang la: %d\n", Min2(a, n));
 	Xuat(a, n);
 }
 */
 /* 4.3 nhap mang : sap xep tang , giam, hien thi kq
 
 #include <stdio.h>
 
 void Nhap(int *a, int n){
 	int i;
 	for(i=0; i<n; i++){
 		printf("Nhap gtri a[%d]: ", i);
 		scanf("%d", &a[i]);
	 }
 }
 void Xuat(int *a, int n){
 	int i;
 	printf("\nMang a:\n");
 	for(i=0; i<n; i++)
 		printf("%d ", a[i]);
 	printf("\n");
 }
 void SwapT(int *a, int n){
 	int i, j;
 	for(i=0; i<n-1; i++)
 	 for(j=i+1; j<n; j++)
 	  if(a[i] > a[j]){
 	  	int t = a[i];
 	  	a[i]  = a[j];
		a[j]  = t;
	   }
 }
 
  void SwapG(int *a, int n){
 	int i, j;
 	for(i=0; i<n-1; i++)
 	 for(j=i+1; j<n; j++)
 	  if(a[i] < a[j]){
 	  	int t = a[i];
 	  	a[i]  = a[j];
		a[j]  = t;
	   }
}
void Swap(int *a, int n, int d){
 	int i, j;
 	for(i=0; i<n-1; i++)
 	 for(j=i+1; j<n; j++)
 	  if(a[i] < a[j] && d == 0){
 	  	int t = a[i];
 	  	a[i]  = a[j];
		a[j]  = t;
	   } else
	   if(a[i] > a[j] && d==1){
 	  	int t = a[i];
 	  	a[i]  = a[j];
		a[j]  = t;
	   }
}
int main(){
	int n;	printf("Nhap so luong phan tu: ");	scanf("%d", &n);
 	int a[n]; printf("Nhap mang:\n");	Nhap(a, n);
 	Xuat(a, n);
 	printf("Tang dan ");
 	Swap(a, n, 1);	Xuat(a, n);
 	printf("Giam dan ");
 	SwapG(a, n);	Xuat(a, n);
}
*/

/* 4.4: Nhap mang, chen x vao vi tri y va dem so lan xuat hien cua x

 #include <stdio.h>
 
 void Nhap(int *a, int n){
 	int i;
 	for(i=0; i<n; i++){
 		printf("Nhap gtri a[%d]: ", i);
 		scanf("%d", &a[i]);
	 }
 }
 void Xuat(int *a, int n){
 	int i;
 	printf("\nMang a:\n");
 	for(i=0; i<n; i++)
 		printf("%d ", a[i]);
 	printf("\n");
 }
 void Chen(int *a, int *m, int x, int y){
 	int n = *m;
 	n++;
 	*m = n;
 	int i;
 	for(i=n-1; i>y; i--)
 		a[i] = a[i-1];
 	a[y] = x;
 }
 int Dem(int *a, int n, int x){
 	int i, count =0;
 	for(i=0; i<n; i++)
 		if(a[i] == x) 	count ++;
 	return count;
 }
 
 int main(){
 	int n;	printf("Nhap so luong phan tu: ");	scanf("%d", &n);
 	int a[n+1]; printf("Nhap mang:\n");	Nhap(a, n);
 	int x, y;	printf("Nhap gtri chen, vi tri chen: ");	scanf("%d%d", &x, &y);
 	Xuat(a, n);
 	Chen(a, &n, x, y);
 	printf("Sau khi chen ");
 	Xuat(a, n);
 	printf("So lan xuat hien cua %d la: %d", x, Dem(a, n, x));
 	
 }
 */ 
 
 /* 4.5 Nhap mang va in ra phan tu gan gtri x nhat
 #include <stdio.h>
 #include <math.h>
 
 void Nhap(int *a, int n){
 	printf("Nhap mang: \n");
 	int i;
 	for(i=0; i<n; i++){
 		printf("Nhap gia tri a[%d]: ", i);
 		scanf("%d", &a[i]);
	 }
 }
 void Xuat(int *a, int n){
 	printf("\nMang a: \n");
 	int i;
 	for(i=0; i<n; i++)
 		printf("%d ", a[i]);
 }
 int Search(int *a, int n, int x){
 	int i, denta = a[0], t;
 	for(i=1; i<n; i++)
 		if (abs(a[i] - x ) < denta) {
 			denta = abs(a[i]-x);
 			t = i;
		 }
	return t;
 }
 int main(){
 	int n; printf("Nhap so luong phan tu: ");	scanf("%d", &n);
 	int a[n];	Nhap(a, n);
 	int x; 	printf("Nhap phan tu doi chieu: "); 	scanf("%d",&x);
 	printf("\nGia tri gan voi %d nhat la: %d", x, a[Search(a, n, x)]);
 }
 */
 /*4.9 Tim so lan xuat hien cac phan tu trong mang;
 
 #include <stdio.h>
 
 void Nhap(int *a, int n){
 	printf("Nhap mang: \n");
 	int i;
 	for(i=0; i<n; i++){
 		printf("Nhap gia tri a[%d]: ", i);
 		scanf("%d", &a[i]);
	 }
 }
 void Xuat(int *a, int n){
 	printf("\nMang a: \n");
 	int i;
 	for(i=0; i<n; i++)
 		printf("%d ", a[i]);
 }
 int main(){
 	int n; printf("Nhap so luong phan tu: ");	scanf("%d", &n);
 	int a[n];	Nhap(a, n);
 	int i, max = a[0];
 	for(i=1; i<n; i++)
 		max = (max > a[i]) ? max : a[i];
 	int b[max];
 	for(i=0; i<n; i++)
 		b[a[i]] = 0;
 	for(i=0; i<n; i++)
 		b[a[i]] ++;
	for(i=0; i<n; i++){
		if(b[a[i]] != 0){
			printf("\n%d  xuat hien %d lan.", a[i], b[a[i]]);
			b[a[i]] = 0;
		}
	}
 }
 */
 /* 4.11. Viet ham sinh so ngau nhien cho n pt khac nhau
 #include <stdio.h>
 #include <stdlib.h>
 
 int Boolean(int *a, int n, int x){
 	int i;
 	for(i=0; i<n; i++ )
 		if(i != x && a[x] == a[i])	return 0;
 	return 1;
 }
 
 void Nhap(int *a, int n){
 	int i;
 	for(i=0; i<n; i++){
 		a[i] =  rand()%10*n;
 		while(Boolean(a, n, i) == 0 )
 				a[i] =  rand()%5;
	 }
 }
 void Xuat(int *a, int n){
 	int i;
 	printf("\nMang: \n");
 	for(i=0; i<n; i++)
 		printf("%d ", a[i]);
 }
 
 int main(){
 	int n; printf("Nhap n: ");	scanf("%d", &n);
 	int a[n]; Nhap(a, n);
 	Xuat(a, n);
 }
 */
 /* 4.2 Nhap mang, roi chen x vao vi tri y;
 #include <stdio.h>
 #include <stdlib.h>
 
 void Nhap(int *a, int n){
 	int i;
 	for(i=0; i<n; i++)
 		a[i] = rand()%10*n;
 }
 void Xuat(int *a, int n){
 	int i;
 	printf("\nMang: \n");
 	for(i=0; i<n; i++){
 		printf("%d ", a[i]);
	 }
 }
 void Chen(int *a, int *n, int x, int y){
 	int m = *n;
 	m++;
 	*n = m;
 	int i;
 	for(i=m-1; i>y; i--)
 		a[i] = a[i-1];
 	a[y] = x;
 }
 void Xoa(int *a, int *n, int x){
 	int i;
 	for(i=x; i<*n-1; i++)
 		a[i] = a[i+1];
 	int m = *n;
 	m--;
 	*n = m;
 }
 void Swap(int *a, int n){
 	int i, j, t;
 	for(i=0; i<n-1; i++)
 	 for(j=i+1; j<n; j++)
 	 	if(a[i]> a[j]){
 	 		t = a[i];
 	 		a[i] = a[j];
 	 		a[j] = t;
		  }
 }
 void ChenA(int *a, int *n, int x){
 	int i, d =1;
 	int m;
 	m = *n;
 	m++;
 	*n = m;
 	if(a[0] > x)	d = 0;
 	if(a[m-1] > x){
 		for(i=0; i<m-2; i++)
		if( (a[i] < x) && (x < a[i+1]) )	break;
		d = i +1;
	 }  else { d = -1; a[m-1] = x;
	 }
	if(d >= 0){
		for(i=m-1; i>d; i--)
		a[i] = a[i-1];
		a[d] = x;	
	}
 }
 int main(){
 	int n; printf("Nhap sl: ");	scanf("%d", &n);
 	int a[n+1]; Nhap(a, n);	Xuat(a, n);
 	int x, y;	printf("\nNhap gtri, vi tri: ");	scanf("%d%d", &x, &y);
 	printf("Mang sau khi chen %d vao vtri %d", x, y);
 	Chen(a, &n, x, y);
 	Xuat(a, n);
 	printf("\nNhap vtri can xoa: "); scanf("%d", &x);
 	Xoa(a, &n, x);
 	Xuat(a, n);
 	printf("\nSap xep:");	Swap(a, n); 	Xuat(a, n);
 	printf("\nNhap gtri can chen: "); scanf("%d", &x);	ChenA(a, &n, x);	Xuat(a, n);
 }
 */
 
 /* Nhap mang n pt roi chen mang b gom m pt vao vi tri x;
 #include <stdio.h>
 #include <stdlib.h>
 
 void Nhap(int *a, int n){
 	int i;
 	for(i=1; i<=n; i++)
 		a[i] = rand()%10*n;
 }
 void Xuat(int *a, int n){
 	int i;
 	printf("\nMang gtri: ");
 	for(i=1; i<=n; i++)
 		printf("%d ", a[i]);
 }
 
 void ChenMang(int *a, int *n, int *b, int m, int x){
 	int c[*n+m];
	int  i;
 	for(i=1; i<=m+*n; i++){
 		if(i < x)	c[i] = a[i];
 		if(i >= x && i < x + m )	c[i] = b[i - x + 1];
 		if(i >= x +m) 	c[i] = a[i - m];
	 }
	x = *n + m;
	*n = x;
	for(i=1; i<=*n; i++)
		a[i] = c[i];
 }
 void Swap(int *a, int n){
 	int i, j;
 	for(i=1; i<n; i++)
 	 for(j=i+1; j<=n; j++)
 	 	if(a[i] > a[j]){
 	 		int t = a[i];
 	 		a[i]= a[j];
 	 		a[j]= t;
		  }
 }
 void ChenA(int *a, int *n, int *b, int m){
 	int i =1, j =1, t;
 	int c[*n + m];
 	for(t=1; t<= *n + m; t++)
 		if(a[i] < b[j] && i<=*n) {
 			c[t] = a[i];
 			i++;
		} else{
			c[t] = b[j];
			j++;
		}
	i = *n + m;
	*n = i;
	for(i=1; i<=*n; i++)
		a[i] = c[i];
 }
 int main(){
 	int n; printf("Nhap sl: "); scanf("%d", &n);
 	int a[n];	Nhap(a, n);	Xuat(a, n);
	Swap(a, n);	Xuat(a, n);
 	int m; printf("\nNhap sl: ");	scanf("%d", &m);
 	int b[m];	Nhap(b, m); Xuat(b, m);	
	Swap(b, m);		Xuat(b, m);
	ChenA(a, &n, b, m);	Xuat(a, n);
 //	int x;	printf("\nNhap vi tri can chen: ");	scanf("%d", &x);
 //	ChenMang(a, &n, b, m, x);
 }
 
 */
 
 /* Xuat ra day con tang dai nhat
 #include <stdio.h>
 #include <stdlib.h>
 
 void Nhap(int *a, int n){
 	int i;
 	for(i=0; i<n; i++)
 		a[i] = rand()%n;
 }
 void Xuat(int *a, int n){
 	printf("\nMang: ");
 	int i;
 	for(i=0; i<n; i++)
 		printf("%d ", a[i]);
 }
 int Boolean(int *a, int x, int y){
 	int i;
 	for(i=x; i<x+y; i++)
 		if(a[i] > a[i+1])	return 0;
 	return 1;
 }
 void Daycon(int *a, int n){
 	int max =1, i, j, x;
 	printf("\nDay con: ");
 	for(i=0; i<n-1; i++)
 		for(j=max; j<n-i-1; j++)
 			if (Boolean(a, i, j) == 1) {
 				if(j > max){
 					x = i;
 					max = j;
				 }
			 }else break;
	for(i=x; i<=max+x; i++)
		printf("%d ", a[i]);
 }
 int main(){
 	int n;	printf("Nhap sl: ");	scanf("%d", &n);
 	int a[n];	Nhap(a, n); Xuat(a, n);
   Daycon(a, n);
 }
 */
 
 /* Tính gia tri cua P = ak.x^k , voi mang cac he so
 
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 void Nhap(int *a, int n){
 	int i;
 	for(i=0; i<n; i++)
 		a[i] = rand()%n;
 }
void Xuat(int *a, int n){
 	printf("\nMang: ");
 	int i;
 	for(i=0; i<n; i++)
 		printf("%d ", a[i]);
 }
 
int P(int *a, int n, int x){
 	int i, sum =0;
 	for(i=0; i<n; i++)
 		sum += a[i]*pow(x, i);
 	return sum;
 }
int Px(int *a, int n, int x){
	int i, sum = 0;
	for(i=1; i<n; i++)
		sum = i*a[i]*pow(x, i-1);
	return sum;
}
void Tong(int *a, int n, int *b, int *c){
	int i;
	for(i=0; i<n; i++)
		c[i] = a[i] + b[i];
}
 int main(){
 	int n;	printf("Nhap sl: ");	scanf("%d", &n);
 	int a[n];	Nhap(a, n); Xuat(a, n);
 	int x;	printf("\nNhap x: ");	scanf("%d", &x);
 	printf("\nP(%d) = %d", x, P(a, n, x));
 	printf("\nP'(%d) = %d", x, Px(a, n, x));
 	int i, b[n], c[n];
 	Nhap(b, n);	Xuat(b, n);
 	Tong(a, n, b, c);
 	for(i=0; i<n; i++)
 		if(i!=n-1) printf("%d*x^%d + ", c[i], i);
 		else	printf("%d*x^%d", c[i], i);
 }
 
 */
 
 // Tính dinh thuc ma tran n x n
 #include <stdio.h>
 #include <math.h>
 
  void Nhap(int a[][100], int n){
  	int i, j;
	printf("\nNhap matrix: \n");
  	for(i=0; i<n; i++)
  		for(j=0; j<n; j++)
  			scanf("%d", &a[i][j]);
  }
  
  void Xuat(int a[][100], int n){
  	int i, j;
  	printf("\nXuat matrix: \n");
  	for(i=0; i<n; i++){
  		for(j=0; j<n; j++)
  			printf("%d ", a[i][j]);
  		printf("\n");
	  }
  }

 void Matrixnew(int a[][100], int n, int b[][100], int x, int y){
 	int i, j, d=0, e=0;
 	for(i=0; i<n-1; i++){
 			for(j=0; j<n-1; j++){
 				if(i == x) d=1;
 				if(j == y) e=1;
 				b[i][j] = a[i+d][e+j];
			 }
			 e = 0;
 }
 }  

  int Det(int a[][100], int n){
  	if(n==1) return a[0][0];
  	if(n==2)	return a[0][0]*a[1][1] -a[0][1]*a[1][0];
	int x = n -1;
	int det = 0, i;
	int b[100][100];
	for(i=0; i<n; i++){
		Matrixnew(a, n, b, i, 0);
		det += pow(-1, i)*a[i][0]*Det(b, x);
	}
	return det;	
  }

  int main(){ 
  	int n;	printf("Nhap n: ");	scanf("%d", &n);
	int a[100][100];	Nhap(a, n);	Xuat(a, n);
	printf("\n%d", Det(a, n));
  	return 0;
  }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
