/* Nhap so n, nhap mang a gom n pt, in xuoi in nguoc dau */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

 void Nhap(float *a, int n){
 	int i;
 	for(i=1; i<=n; i++){
 		printf("Nhap a[%d]: ", i);
 		scanf("%f", &a[i]);
	 }
 }
 void XuatXuoi(float *a, int n){
 	int i;
 	for(i=1; i<=n; i++)
 		printf("%0.2f\t", a[i]);
 	printf("\n");
 }
 void XuatNguoc(float *a, int n){
 	int i;
 	for(i=n; i>=1; i--)
 		printf("%0.2f\t", a[i]);
 	printf("\n");
 }
 void HoanDoi(float *a,int n, int x, int y, int z){
 	
 }
 
 int main(){
 	int n; 	printf("Nhap so luong phan tu: ");	scanf("%d", &n);
 	float a[n]; Nhap(a, n);
 	printf("In xuoi: "); XuatXuoi(a, n);
 	printf("In nguoc: ");	XuatNguoc(a, n);
 	printf("Nhap 3 vi tri can hoan doi: "); int x, y, z; scanf("%d%d%d", &x, &y, &z);
 //	Hoandoi(a, n, x, y, z);	float t, *b;
    float  t;
 	t = a[x];
 	a[x] = a[z];
 	a[z] = a[y];
 	a[y] = t;
	printf("Day sau khi hoan doi: "); XuatXuoi(a, n);
 }
 
