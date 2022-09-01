/*
#include <stdio.h>

float TongTB(int x, int y, int z){
	float KQ = (x + y + z)/3.0;
	// phai la 3.0 vi neu de 3 thi mac dinh la kieu int / int la lay phan nguyen
	return KQ;
}
int main(){
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	// C1
	printf("C1:	%d + %d + %d = %0.2f\n", x, y, z, TongTB(x, y, z));// vi Ham TongTB tra ve 1 gtri kieu so thuc
	
	// C2;
	float TB = TongTB(x, y, z);
	printf("C2:	%d + %d + %d = %0.2f\n", x, y, z, TB);
}
2:

#include <stdio.h>
#include <math.h>	// thu vien toan hoc

void TimNghiemPT2(float a, float b, float c){
	float denta = b*b - 4*a*c;
	if(denta < 0){
		printf("Phuong trinh vo nghiem");
		return; // ket thuc ham con luon
	}
	if(denta == 0){
		printf("Phuong trinh co nghiem kep x = %0.2f", -b/(2*a));
		return;
	}
	float x1 = (-b-sqrt(denta))/(2*a);
	float x2 = (-b+sqrt(denta))/(2*a);
	printf("Phuong trinh co 2 no phan biet: \nx1 = %0.2f\nx2 = %0.2f", x1, x2);	// \n: xuong dong
}
int main(){
	float a, b, c;
	do{
		scanf("%f", &a);
	}while(a == 0);	// Nhap truoc roi moi kiem tra
	scanf("%f%f", &b, &c);
	TimNghiemPT2(a, b, c);
}

4:

#include <stdio.h>
#include <math.h>

long TinhTong(int *x, int n){ // *x: con tro tro den vi tri dau cua mang x, cung tuc la dai dien cho mang x luon
	long i, sum = 0; // Nho phai khoi tao gtri ban dau cua sum
	for(i=0; i<n; i++)
		sum += x[i]*x[i];
	//	sum += pow(x[i], 2);	Cong thuc so mu
	return sum;
}
void Sort(int *a, int n){
	int i, j;
	for(i=0; i<n; i++)
		for(j=i+1; j<n; j++) // duyet xem co phan tu nao nho hon phan tu o vi tri i khong
			if(a[i] > a[j]){
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
}
int main(){
	int n, i;
	scanf("%d", &n);
	int a[n]; // Khai bao mang x gom n phan tu 
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	printf("%ld\n", TinhTong(a, n)); // Khong nhat thiet phai dat ten giong voi bien trong ham, chi can dung vi tri
	Sort(a, n);
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
}

5:

#include <stdio.h>
#include <stdlib.h>
int ** Nhap(int m, int n){
	int **a;
	a = malloc(m*sizeof(int*)); // cap phat vung nho cho m dong
	int i, j;
	for(i=0; i<m; i++) // cap phat vung nho cho n cot
		a[i] = malloc(n*sizeof(int));
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			scanf("%d", &a[i][j]);
	return a; // Tra ve con tro ma tran 2 chieu
}
void Xuat(int **a, int m, int n){
	int i, j;
	for(i=0; i<m; i++){
		for(j=0; j<n; j++)	// Xuat cac phan tu cua 1 dong
			printf("%d ", a[i][j]);
		printf("\n"); // Sau khi xuat xong cac phan tu cua 1 dong phai xuong dong
	}
}
int ** Tich(int **a, int m, int n, int **b, int u, int v){
	int **c = malloc(sizeof(int*)*m);
	int i, j, k;
	for(i=0; i<m; i++)
		c[i] = malloc(sizeof(int)*v);
	for(i=0; i<m; i++)
		for(j=0; j<v; j++){
			c[i][j] = 0;
			for(k=0; k<n; k++)
				c[i][j] += a[i][k]*b[k][j];
		}
	return c;
}
int main(){
	int m, n;
	printf("Nhap kich thuoc ma tran: "); scanf("%d%d", &m, &n);
	int **a = Nhap(m, n); // khai bao con tro cua mang 2 chieu
	Xuat(a, m, n);
	int u, v;
	printf("Nhap kich thuoc ma tran: "); scanf("%d%d", &u, &v);
	int **b = Nhap(u, v); // khai bao con tro cua mang 2 chieu
	
	if(u != n)
		printf("Khong the nhan");
	else{
		int **c = Tich(a, m, n, b, u, v);
		Xuat(c, m, v);
	}
}
8:

#include <stdio.h>
long GT1(int n){	// do gt kha lon nen de kieu lon
	int i;
	long KQ = 1; // khoi tao bang 1 vi lien quan den tich
	for(i=1; i<=n; i++)
		KQ *= i;
	return KQ;
}
long GT2(int n){
	if(n <= 1) return 1;
	return n*GT2(n-1); // pp de quy
}
int main(){
	int n;
	scanf("%d", &n);
	printf("%d! = %ld\n",n, GT1(n));
	printf("%d! = %ld",n, GT2(n));
}
9:

#include <stdio.h>

double P(n, x){
	if(n == 0)	return 1;
	if(n == 1) 	return x;
	return (2*n - 1)*1.0*x*P(n-1, x)/n - (n - 1)*P(n-2, x)*1.0/n;
}
int main(){
	int n, x;
	scanf("%d%d", &n, &x);
	printf("P(%d) bac %d = %0.2lf", x, n, P(n, x));
}


// Lap ham tinh tong 2 so

#include <stdio.h>

int Tong2So(int a, int b){
	int c;
	c = a + b;
	return c;
}

void Tong2Sovoid(int a, int b, int *c){ // cho dia chi
	*c = a + b;
	return;
}
int main(){
	int a, b, c;
	scanf("%d%d", &a, &b);
	printf("su dung bt %d\n", a + b);
	printf("su dung ham %d\n", Tong2So(a, b));
	Tong2Sovoid(a, b, &c);
	printf("su dung bt %d\n", c);
}

// Nhap mang a gom n phan tu, xuat no
#include <stdio.h>

void Nhap(int *a, int n){ // dia chi a[0]: *a <=> &a[0]
	int i;
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	return;
}
void Xuat(int *a, int n){
	int i;
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
}
int *Nhap2(int n){
	int *a = malloc(sizeof(int)*n); // mang trc
	int i;
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	return a;
}
int **NhapMatrix(int m, int n){
	int i, j;
	int **a = malloc(sizeof(int*)*m); // cap phat bo nho cho m dong
	for(i=0; i<m; i++)
		a[i] = malloc(sizeof(int)*n);// cap phat bo nho cho n cot
	// cau lenh
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			scanf("%d", &a[i][j]);
	return a;	
}
void XuatMatrix(int **a, int m, int n){
	int i, j;
	for(i=0; i<m; i++){
		for(j=0; j<n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}
// Tinh n!
void GT1(int n, long *gtri){
	*gtri = 1;
	int i;
	for(i=1; i<=n; i++)
		*gtri *= i;
}
long GT2(int n){
	long gtri = 1;
	int i;
	for(i=1; i<=n; i++)
		gtri *= i;
	return gtri;
}
long GT3(int n){
	if(n == 1 || n == 0)	return 1;
	return n*GT3(n-1);
}
int main(){
//	int n, i;
//	scanf("%d", &n);
//	int *a = Nhap2(n);
//	Xuat(a, n);
//	for(i=0; i<n; i++)
//		scanf("%d", &a[i]);
//	for(i=0; i<n; i++)
//		printf("%d ", a[i]);

//	int m, n;
//	scanf("%d%d", &m, &n);
//	int **a = NhapMatrix(m, n);
//	XuatMatrix(a, m, n);
	int n;
	scanf("%d", &n);
	long gtri;
	GT1(n, &gtri);
	printf("1: %d \n", gtri);
	printf("2: %d \n", GT2(n));
	printf("3: %d \n", GT3(n));
}

#include <stdio.h>

int main(){
	int n;
	FILE *output;
	output = fopen("D:\\C\\AItest.txt", "w");
	scanf("%d", &n);
	fprintf(output, "%d", n);
	
}
*/
#include <stdio.h>

typedef struct SoPhuc{
	int Thuc;
	int Ao;
}SP;

// Nhap
SP Nhap1(){
	SP a;
	scanf("%d%d", &a.Thuc, &a.Ao);
	return a;
}
void Nhap2(SP *a){
	scanf("%d%d", &a->Thuc, &a->Ao);
}
void NhapDS(SP *a, int n){
	int i;
	for(i=0; i<n; i++)
		a[i] = Nhap1();
}
// Xuat
void Xuat(SP a){
	printf("%d + (%di)\n", a.Thuc, a.Ao);
}
void XuatDS(SP *a, int n){
	int i;
	for(i=0; i<n; i++)
		Xuat(a[i]);
}

int main(){
	int n =5;
	SP a[5];
	NhapDS(a, 5);
	XuatDS(a, 5);
}

