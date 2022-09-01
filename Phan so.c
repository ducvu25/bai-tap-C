/* Tao struct phan so :
 + Viet ham nhap phan so
 + rut gon phan so
 + tong, hieu 2 phan so
 + Tich, thuong 2 phan so
 + viet menu thuc hiejn chuc nang tren
 */
 
#include <stdio.h>
#include <math.h>

typedef struct phanso{
	int tu;
	int mau;
}PS;

PS Nhap(){
	PS a;
	printf("\nNhap phan so: \n");
	printf("Nhap tu so: "); scanf("%d", &a.tu);
	do {
		printf("Nhap mau so: "); scanf("%d", &a.mau);
	}while(a.mau == 0);
	return a;
}
void Xuat(PS a){
	printf("%d/%d\n", a.tu, a.mau);
}
int UCLN(int a, int b){
	if(a <0) a *= -1;
	if(b <0) b *= -1;
	if(a ==0 && b!=0)	return b;
	if(b ==0 && a!=0)	return a;
	if(a > b) return UCLN(a%b, b);
	if(b > a) return UCLN(a, b%a);
}
void Rutgon( PS *a){
	int d = UCLN(a->tu, a->mau);
	a->tu /= d;
	a->mau /= d;
}
PS Tong(PS a, PS b){
	PS c;
	c.tu = a.tu*b.mau + a.mau*b.tu;
	c.mau = a.mau*b.mau;
	Rutgon(&c);
	return c;
}
PS Hieu(PS a, PS b){
	PS c;
	c.tu = a.tu*b.mau - a.mau*b.tu;
	c.mau = a.mau*b.mau;
	Rutgon(&c);
	return c;
}
PS Nghichdao (PS a){
	PS c;
	c.tu = a.mau;
	c.mau = a.tu;
	return c;
}
PS Tich(PS a, PS b){
	PS c;
	c.tu = a.tu*b.tu;
	c.mau = a.mau*b.mau;
	Rutgon(&c);
	return c;
}
PS Thuong(PS a, PS b){
	PS c = Tich(a, Nghichdao(b));
	Rutgon(&c);
	return c ;
}

int main(){
	int n;
	do{
		printf("\n\nChuc nang: \n1. Nhap, xuat phan so. \n2. Rut gon phan so. \n3. Tong, hieu n phan so. \n4. Tich, thuong n phan so.\n0. Thoat. \nVui long chon thao tac: ");
		scanf("%d", &n);
		switch (n) {
			case 1: {
				PS a; 	a = Nhap() ;
				printf("\n");	Xuat(a);
				break;
			}
			case 2: {
				PS a; a = Nhap() ; printf("\n");
				printf("Truoc: "); Xuat(a);
				Rutgon(&a);
				printf("Sau: "); Xuat(a);
				break;
			}
			case 3: {
				PS a, b; a = Nhap();	b = Nhap(b);
				PS c =Tong(a, b);
				printf("%d/%d + %d/%d = %d/%d\n",a.tu, a.mau, b.tu, b.mau, c.tu, c.mau );
				c = Hieu(a, b);
				printf("%d/%d - %d/%d = %d/%d\n",a.tu, a.mau, b.tu, b.mau, c.tu, c.mau );
				break;
			}
			case 4: {
				PS a, b; a = Nhap();	b = Nhap(b);
				PS c =Tich(a, b);
				printf("%d/%d * %d/%d = %d/%d\n",a.tu, a.mau, b.tu, b.mau, c.tu, c.mau );
				c = Thuong(a, b);
				printf("%d/%d : %d/%d = %d/%d\n",a.tu, a.mau, b.tu, b.mau, c.tu, c.mau );
				break;
			}
			case 0: {
				printf("\n-------- Cam on da su dung chuong trinh ---------");
				break;
			}
		}
	}while( n != 0);
}
