/* Tao struct phan so :
 + Viet ham nhap phan so
 + rut gon phan so
 + tong, hieu 2 phan so
 + Tich, thuong 2 phan so
 + viet menu thuc hiejn chuc nang tren

 
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
*/

/* Tao struct so phuc :
 + ham nhap, xuat
 + Viet ham tinh tong, hieu, tich thuong
 + menu (Nhap esc ket thuc)
 */
#include <stdio.h>

typedef struct sophuc{
	float thuc;
	float ao;
} SP;
void Xuat(SP a){
	if(a.ao > 0)
	printf("%0.2f + %0.2fi", a.thuc, a.ao);
	else
	printf("%0.2f - %0.2fi", a.thuc, a.ao*-1);
}
SP Nhap(){
	SP c;
	printf("\nNhap so phuc: ");
	printf("\nNhap phan thuc: ");	scanf("%f", &c.thuc);
	printf("Nhap phan ao: ");	scanf("%f", &c.ao);
	return c;
}

SP Tong(SP a, SP b){
	SP c;
	c.thuc = a.thuc + b.thuc;
	c.ao = a.ao + b.ao;
	return c;
}
SP Hieu(SP a, SP b){
	SP c;
	c.thuc = a.thuc - b.thuc;
	c.ao = a.ao - b.ao;
	return c;
}
SP Tich(SP a, SP b){
	SP c;
	c.thuc = a.thuc*b.thuc - b.ao*a.ao;
	c.ao = a.ao*b.thuc + b.ao*a.thuc;
	return c;
}
SP Thuong(SP a, SP b){
	SP c;
	float denta = b.thuc*b.thuc + b.ao*b.ao;
	SP d ;
	d.thuc = b.thuc;
	d.ao = -1*b.ao;
	c = Tich(a, d);
	c.thuc /= denta;
	c.ao  /= denta;
	return c;
}

int main(){
	int n;
	do{
		printf("\n\n\t\tChuc nang: \n1.Nhap, xuat so phuc. \n2.Tong 2 so phuc. \n3. Hieu 2 so phuc. \n4. Tich 2 so phuc. \n5. Thuong 2 so phuc. \n0.Thoat. \nLua chon: ");	scanf("%d", &n);
		switch (n){
			case 1: {
				SP a; 
				a = Nhap(); 
				Xuat(a);
				printf("\n");
				break;
			}
			case 2: {
				SP a; a = Nhap();
				SP b; b = Nhap();
				SP c; c = Tong(a, b);
				Xuat(a); printf(" + "); Xuat(b); printf(" = ");	Xuat(c);	printf("\n");
				break;
			}
			case 3: {
				SP a; a = Nhap();
				SP b; b = Nhap();
				SP c; c = Hieu(a, b);
				Xuat(a); printf(" - "); Xuat(b); printf(" = ");	Xuat(c);	printf("\n");
				break;
			}
			case 4: {
				SP a; a = Nhap();
				SP b; b = Nhap();
				SP c; c = Tich(a, b);
				printf("("); Xuat(a); printf(") * ("); Xuat(b); printf(") = ");	Xuat(c);	printf("\n");
				break;
			}
			case 5: {
				SP a; a = Nhap();
				SP b; b = Nhap();
				SP c; c = Thuong(a, b);
				printf("("); Xuat(a); printf(") : ("); Xuat(b); printf(") = ");	Xuat(c);	printf("\n");
				break;
			}
			case 0: {
				printf("---------- Cam on da su dung ------------");
				break;
			}
		}
		
	}while (n != 0);
	return 0;

}
