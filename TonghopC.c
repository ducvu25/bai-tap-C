/* Tao chuong trinh thuc hien :
 - Toan cao cap: 
   + Tong, hieu, tich 2 ma tran
   + ma tran chuyen vi
   + ma tran mu n
   + dinh thuc
   + ma tran nghich dao
   + ma tran cheo hoa
  - Giai tich:
   + giai nghiem pt bac 1, 2
   + dao ham cap n 
   + tong cac so lon
   + cap so cong, cap so nhan: 
    	+ tim Un, tong n pt dau
   - Mot so bai toan khac
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

void NhapMatrix( float a[][100], int m, int n){
	int i, j;
	printf("\nNhap ma tran kich co %d x %d:\n", m, n);
	for(i=0; i<m; i++)
	 for(j=0; j<n; j++)
	 	scanf("%f", &a[i][j]);
}
void XuatMatrix( float a[][100], int m, int n){
	int i, j;
	for(i=0; i<m; i++){
		for(j=0; j<n; j++)
	    	printf("\t%0.2f", a[i][j]);
	 	printf("\n");
	}
}
void TongMatrix(float a[][100], int m, int n, float b[][100], float c[][100]){
	int i, j;
	for(i=0; i<m; i++)
	 for(j=0; j<n; j++)
	 	c[i][j] = a[i][j] + b[i][j];
}
void HieuMatrix(float a[][100], int m, int n, float b[][100], float c[][100]){
	int i, j;
	for(i=0; i<m; i++)
	 for(j=0; j<n; j++)
	 	c[i][j] = a[i][j] - b[i][j];
}
void TichMatrix(float a[][100], int m, int n, float b[][100], int x, int y, float c[][100]){
	int i, j, t;
	for(i=0; i<m; i++)
	 for(j=0; j<y; j++){
	 	c[i][j] = 0;
	 	for(t=0; t<n; t++)
	 	 c[i][j] += a[i][t]*b[t][j];
	 }
}
void ChuyenVi(float a[][100], int m, int n, float b[][100]){
	int i, j;
	for(i=0; i<m; i++)
	 for(j=0; j<n; j++)
	  b[j][i] = a[i][j];
	
}
void XoaCotnHangm(float a[][100], int m, int n, int x, int y, float b[][100]){
	int i, j, p = 0, q =0;
	for(i=0; i<m; i++)
		if(i != x){
			for(j=0; j<n; j++)
				if(j != y){
					b[p][q] = a[i][j];
					q ++;
				}
			q =0;
			p++;
		}
}
float Det(float a[][100], int n){
	if( n == 1) return a[0][0];
	if(n == 2) return a[0][0]*a[1][1] - a[0][1]*a[1][0];
	int i, j, det = 0;
	for(i=0; i<n; i++){
		float b[100][100];
		XoaCotnHangm(a, n, n, i, 0, b);
		det += pow(-1, i)*a[i][0]*Det(b, n -1);
	}
    return det;
}
void NghichdaoMatrix( float a[][100], int n, float b[][100]){
	if(n == 1) b[0][0] = -1*a[0][0];
	else{
		float det = Det(a, n);
		int i, j;
		float d[100][100];
		float c[100][100];
		for(i=0; i<n; i++)
			for(j=0; j<n; j++){
				XoaCotnHangm(a, n, n, i, j, d);
				c[i][j] = pow(-1, i+j)*Det(d, n-1)/det;
			}
	ChuyenVi(c, n, n, b);
	}
}
void MunMatrix(float a[][100], int n, int x, float b[][100]){
	if(x>0){
	int i, j, t;
	for(i=0; i<n; i++)
		for(j =0; j<n; j++) 
		  b[i][j] = a[i][j];
	float c[100][100];
	for(t=1; t<x; t++){
			TichMatrix(b, n, n, a, n, n, c);
			for(i=0; i<n; i++)
				for(j =0; j<n; j++) 
				  b[i][j] = c[i][j];
	}
	}
	if(x<0){
		float c[100][100];
		float d[100][100];
		NghichdaoMatrix(a, n, c);
		int i, j, t;
		for(i=0; i<n; i++)
			for(j =0; j<n; j++) 
			  b[i][j] = c[i][j];
		for(t=x; t<-1; t++){
			TichMatrix(b, n, n, c, n, n, d);
			for(i=0; i<n; i++)
				for(j =0; j<n; j++) 
				  b[i][j] = d[i][j];
		}
	}
	if(x==0){
	int i, j;
	for(i=0; i<n; i++)
		for(j =0; j<n; j++) 
		  b[i][j] = 1;
	}
}
void MatrixXoanOc(int m, int n){
/*     m = 3, n = 3
		 y2		y1
    x1  a00 a01 a02	
    	a10	a11 a12
    	a20 a21 a22 x2
    */
	int a[100][100];
	int x1, x2, x = 0, y =0, y1, y2, d = 0;
	for(x1 = x; x1<n - x; x1++)
		if(x1 == n - 1 - x){
			for(y1 = y; y1<m - y; y1++)
				if(y1 == m - 1 - y){
					for(x2 = x1; x2 >= x; x2--)
						if(x2 == x){
							for(y2 = y1; y2 >= y; y2--)
								if(y2 == y){
									y++;
									x1 = x;
									x++;
								}else{
									a[y2][x2] = d;
									d++;
								}
						}else{
							a[y1][x2] = d;
							d++;	
						}
				}else{
					a[y1][x1] = d;
					d++;
				}
		}else{
			a[y][x1] = d;
			d++;	
		}
	for(x=0; x<m; x++){
		for(y=0; y<n; y++)
			printf("\t%d", a[x][y]);
		printf("\n");
	}

}

void Daoham(int *a, int *n, int k){
	int i, j, d = *n;
	for(j=1; j<=k; j++){
		for(i=0; i <d; i++)
			a[i] = (i+1)*a[i+1];
		d--;
	}

	*n = d;
}

void XoaXuongDong(char *a){
	if(a[strlen(a) - 1] == '\n')
	 a[strlen(a) - 1] = '\0';
}
void Xoa0(char *a){
	while (strlen(a) > 1 && a[0] == 48)
		strcpy(a, a+1);
}
void StrRev(char *a, char *b){
	strrev(a);
	strcpy(b, a);
	strrev(a);
}
int SS(char *a, char *b){
	int i;
	if(strlen(a) > strlen(b))	return 1;
	if(strlen(a) < strlen(b))	return 0;
	for(i=0; i<strlen(a); i++)
	if(a[i] > b[i]) return 1;
	else
	if(a[i] < b[i])return 0;
	return 2;
}
void GanGtri(char *a, char *b, char *x, char *y){
	if(SS(a, b) > 0){
		StrRev(a, x);
		StrRev(b, y);
	}else{
		StrRev(b, x);
		StrRev(a, y);
	}
}
void Tanga(char *a, int n){
	if(a[n] > 9){
		int d = a[n]/10;
		a[n] -= d*10 - 48;
		a[n+1] = d;
	}else{
		a[n] += 48;
		a[n+1] = 0;
	}
}
void Tongab(char *a, char *b, char *c){
	char x[100], y[100];
	int i;
	GanGtri(a, b, x, y);
	c[0] = x[0] - 48 + y[0] - 48;
	Tanga(c, 0);
	for(i=1; i<strlen(x); i++)
		if(i <strlen(y)){
			c[i] += (x[i] - 48) + (y[i] - 48);
			Tanga(c, i);
		}else{
			c[i] += x[i] - 48;
			Tanga(c, i);
		}
	Tanga(c, i);
	strrev(c);
	Xoa0(c);

}
void Giama(char a[100], int n){
	if(a[n] < 0){
		a[n] += 48 + 10;
		a[n+1] = -1;
	}else{
		a[n] += 48;
		a[n+1] = 0;
	}
}
void Hieuab(char *a, char *b, char *c){
	char x[100], y[100];
	int i;
	GanGtri(a, b, x, y);
	c[0] = x[0] - y[0];
	Giama(c, 0);
	for(i=1; i<strlen(x); i++)
		if(i < strlen(y)){
			c[i] += x[i] - y[i];
			Giama(c, i);
		}else{
			c[i] += (x[i] - 48);
			Giama(c, i);
		}
		strrev(c);
		Xoa0(c);
	if(SS(a, b) == 0){
		strcpy(x, c);
		c[0] = '-';
		strcpy(c+1, x);
	}
}
void Tich(char *a, char b, char *c){
	if(b == 48){
		strcpy(c, "0");
	}else{
		int i;
		strrev(a);
		c[0] = (a[0] - 48)*(b-48);
		Tanga(c, 0);
		for(i=1; i<strlen(a); i++ ){
			c[i] += (a[i] - 48)*(b-48);
			Tanga(c, i);
		}
	Tanga(c, i);
	strrev(c);
	Xoa0(c);
	strrev(a);	
	}
}
void Tichab(char *a, char *b, char *c){
	char x[100], y[100], z[] = "0" ;
	int i, j;
	for(i=strlen(b) -1; i>=0; i--){
		Tich(a, b[i], x);
		for(j=0; j<strlen(b) - 1 - i; j++)
			x[strlen(x)] = 48;
		printf("\n %s", x);
		Tongab(z, x, c);
		strcpy(z, c);
	}
}
void Thuongab(char *a, char *b, char *c, char *d){
	strcpy(c, "0");
	if(SS(a, b) == 0)
		strcpy(d, a);
	else{
		char x[100];
		strcpy(x, a);
		char y[100];
		while(SS(x, b)  != 0){
			Hieuab(x,b, y);
		    if(SS(x, b) == 0)
		    	break;
			Tongab(c, "1", c);
			strcpy(x, y);
		}
		strcpy(d, x);
	}
}

typedef struct Sophuc{
	float Thuc;
	float Ao;
} SP;
void NhapSP( SP *a){
	printf("\nNhap phan thuc: "); scanf("%f", &a->Thuc);
	printf("Nhap phan ao: "); scanf("%f", &a->Ao);
}
void XuatSP( SP a){
	if(a.Ao > 0)
	printf("%0.2f + %0.2fi", a.Thuc, a.Ao);
	else
	if(a.Ao < 0)
	printf("%0.2f + (%0.2fi)", a.Thuc, a.Ao);
	else
	printf("%0.2f", a.Thuc);
}
float Modun(SP a){
	return sqrt(a.Ao*a.Ao + a.Thuc*a.Thuc);
}
SP LienHopSP( SP a){
	SP c;
	c.Thuc = a.Thuc;
	c.Ao = -1*a.Ao;
	return c;
}
SP TongSP( SP a, SP b){
	SP c;
	c.Thuc = a.Thuc + b.Thuc;
	c.Ao = a.Ao + b.Ao;
	return c;
}
SP HieuSP( SP a, SP b){
	SP c;
	c.Thuc = a.Thuc - b.Thuc;
	c.Ao = a.Ao - b.Ao;
	return c;
}
SP TichSP( SP a, SP b){
	SP c;
	c.Thuc = a.Thuc*b.Thuc - a.Ao*b.Ao;
	c.Ao = a.Ao*b.Thuc + a.Thuc*b.Ao;
	return c;
}
SP ThuongSP(SP a, SP b){
	SP c;
	float modun = pow(Modun(b), 2);
	SP d = LienHopSP(b);
	c = TichSP(a, d);
	c.Ao /= modun;
	c.Thuc /= modun;
	return c;
}
typedef struct PhanSo{
	int Tu;
	int Mau;
} PS;
void ChuanHoaPS(PS *a){
	if(a->Mau < 0 && a->Tu <0){
		a->Mau *= -1;
		a->Tu *= -1;
	}else
	if(a->Mau <0 && a->Tu >0){
		a->Mau *= -1;
		a->Tu *= -1;
	}
}
void NhapPS( PS *a){
	printf("Nhap tu so, mau so: "); scanf("%d%d", &a->Tu, &a->Mau);
	ChuanHoaPS(a);
}
void XuatPS( PS a){
	if(a.Tu % a.Mau == 0){
		printf("%d", a.Tu /a.Mau);
	}else
	if(a.Tu < 0){
		printf("(%d) / %d ", a.Tu, a.Mau);
	}else
	if(a.Tu > 0){
		printf(" %d / %d ", a.Tu, a.Mau);
	}else
		printf("0");
}
int UCLN(int a, int b){
	if(a <0) a *= -1;
	if(b <0) b *= -1;
	if(a == b) return a;
	if(a == 0) return b;
	if(b == 0) return a;
	if(a > b) return UCLN(a%b, b);
	if(b > a) return UCLN(a, b%a);
}
PS TongPS(PS a, PS b){
	PS c;
	int u = UCLN(a.Mau, b.Mau);
	c.Tu = a.Tu*b.Mau + b.Tu*a.Mau;
	c.Tu /= u;
	c.Mau = a.Mau*b.Mau;
	c.Mau /= u;
	return c;
}
PS HieuPS(PS a, PS b){
	PS c;
	int u = UCLN(a.Mau, b.Mau);
	c.Tu = a.Tu*b.Mau - b.Tu*a.Mau;
	c.Tu /= u;
	c.Mau = a.Mau*b.Mau;
	c.Mau /= u;
	return c;
}
void TriTuyetDoiPS(PS *a){
	if(a->Tu < 0) a->Tu *= -1;
}
PS TichPS(PS a, PS b){
	PS c;
	c.Tu = a.Tu*b.Tu;
	c.Mau = a.Mau*b.Mau;
	int u =UCLN(c.Tu, c.Mau);
	c.Tu /= u;
	c.Mau /= u;
	return c;
}
PS NghichDaoPS(PS a){
	PS c;
	c.Tu = a.Mau;
	c.Mau = a.Tu;
	ChuanHoaPS(&c);
	return c;
}
PS ThuongPS(PS a, PS b){
	PS c, d;
	d = NghichDaoPS(b);
	ChuanHoaPS(&d);
	c = TichPS(a, d);
	return c;
}

int KTNT(int a){
	int i;
	if(a < 2) return 0;
	for(i=2; i<=sqrt(a); i++)
		if(a %i ==0) return 0;
	return 1;
}
int KTSD(int a){
	int sum =0;
	int i;
	for(i=1; i<=sqrt(a); i++){
		if(a%i == 0 && a/i != i)
			sum += i + a/i;
		if(a%i == 0 && i == a/i)
			sum += i;
	}
	if( sum - a == a) 
	return 1;
	return 0;
}

int main(){
	int k1;
	do{
		printf("Chuc nang: \n");
		printf("1. Toan cao cap: \n\t + Tong 2 ma tran. \n\t + Hieu 2 ma tran.\n\t + Tich 2 ma tran. \n\t +Ma tran chuyen vi. \n\t + Ma tran mu n. \n\t + Tinh dinh thuc. \n\t + Ma tran nghich dao. \n\t + Ma tran cheo hoa.\n");
		printf("2. Giai tich. \n\t + Tim nghiem phuong trinh. \n\t + Dao ham. \n\t + Cac phep toan co ban voi so lon. \n\t + Cap so cong, cap so nhan.\n\t + So phuc.\n\t + Phan so.\n");
		printf("3. Mot so bai toan ve day so: \n\t + Day so fibonaci. \n\t + Day so nguyen to. \n\t + Day so chinh phuong. \n\t + Day so dep.\n");
		printf("4. Ve mot so hinh. \n\t + Tam giac can. \n\t + Tam giac vuong. \n\t + Hinh thoi. \n\t + Hinh chiec no. \n\t + Hinh canh dieu.\n\t + Hinh cay thong.\n");
		printf("0. Thoat.\n");
		printf("Su dung chuc nang: "); scanf("%d", &k1);
		switch (k1){
			printf("\n");
			case 1: {
				int k2;
				do{
					printf("\nXin chao! Toi la Dai so!\nToi co cac chuc nang sau:\n");
					printf("\t 1.1. Tong 2 ma tran. \n\t 1.2. Hieu 2 ma tran. \n\t 1.3. Tich 2 ma tran. \n\t 1.4. Ma tran chuyen vi. \n\t 1.5. Dinh thuc. \n\t 1.6. Ma tran nghich dao. \n\t 1.7. Ma tran mu n. \n\t 1.8. Ma tran xoan oc.\n\t 1.0. Thoat.\n");
					printf("Su dung chuc nang: ");	scanf("%d", &k2);
					int m, n;
					float a[100][100];
					int x, y;
					float b[100][100];
					float c[100][100];
					switch (k2){
						case 1:{
							printf("Nhap kich co m x n: "); scanf("%d%d", &m, &n);
							NhapMatrix(a, m, n);
							printf("Nhap kich co m x n: "); scanf("%d%d", &x, &y);
							if(m!= x || n!= y)
								printf("Khong the cong do khong cung kich thuoc! Vui long xem lai!\n");
							else{
								NhapMatrix(b, x, y);
								TongMatrix(a, m, n, b, c);
								XuatMatrix(c, m, n);
							}
							break;
						}
						case 2:{
							printf("Nhap kich co m x n: "); scanf("%d%d", &m, &n);
							NhapMatrix(a, m, n);
							printf("Nhap kich co m x n: "); scanf("%d%d", &x, &y);
							if(m!= x || n!= y)
								printf("Khong the tru do khong cung kich thuoc! Vui long xem lai!\n");
							else{
								NhapMatrix(b, x, y);
								HieuMatrix(a, m, n, b, c);
								XuatMatrix(c, m, n);
							}
							break;
						}
						case 3:{
							printf("Nhap kich co m x n: "); scanf("%d%d", &m, &n);
							NhapMatrix(a, m, n);
							printf("Nhap kich co m x n: "); scanf("%d%d", &x, &y);
							if(n != x)
								printf("Khong the nhan do khong cung kich thuoc! Vui long xem lai!\n");
							else{
								NhapMatrix(b, x, y);
								TichMatrix(a, m, n, b, x, y, c);
								XuatMatrix(c, m, y);
							}
							break;
						}
						case 4:{
							printf("Nhap kich co m x n: "); scanf("%d%d", &m, &n);
							NhapMatrix(a, m, n);
							ChuyenVi(a, m, n, b);
							printf("Ma tran chuyen vi:\n");
							XuatMatrix(b, n, m);
							break;
						}
						case 5:{
							printf("Nhap cap ma tran: "); scanf("%d", &n);
							NhapMatrix(a, n, n);
							float t = Det(a, n);
							printf("Det(A) = %0.2f\n", t);
							break;
						}
						case 6:{
							printf("Nhap cap ma tran: "); scanf("%d", &n);
							NhapMatrix(a, n, n);
							float t = Det(a, n);
							if(t == 0)
								printf("Ma tran khong kha nghich.\n");
							else {
								float b[100][100];
								NghichdaoMatrix(a, n, b);
								XuatMatrix(b, n, n);
							}
							break;
						}
						case 7:{
							printf("Nhap cap ma tran: "); scanf("%d", &n);
							NhapMatrix(a, n, n);
							int x; printf("Nhap so mu: "); scanf("%d", &x);
							MunMatrix(a, n, x, b);
							printf("A^%d = \n", x);
							XuatMatrix(b, n, n);
							break;
						}
						case 8:{ 
							printf("Nhap kich thuoc m x n: "); 	scanf("%d%d", &m, &n);
							MatrixXoanOc(m, n);
							break;
						}
						case 0:{
							printf("..............Da thoat Dai so...............\n\n");
							break;
						}
					}
				}while(k2 != 0);
				printf("\n\n");
				break;
			}
			case 2: {
				int k2;
				do{
					printf("\nChao mung den voi Giai tich!\nChung toi co cac chuc nang sau:");
					printf("\n\t 2.1. Tim nghiem phuong trinh. \n\t 2.2. Dao ham. \n\t 2.3. Cac phep toan co ban voi so lon. \n\t 2.4. Cap so cong, cap so nhan.\n\t 2.5. So phuc.\n\t 2.6. Phan so.\n\t 2.0. Thoat.\n");
					printf("Su dung chuc nang: ");	scanf("%d", &k2);
					switch (k2){
						case 1:{
							int k3;
							do{
								printf("\nChuc nang tim nghiem phuong trinh: \n");
								printf("\t\t 2.1.1. Bac 1.\n\t\t 2.1.2. Bac 2.\n\t\t 2.1.0. Thoat.\n");
								printf("Su dung chuc nang: ");	scanf("%d", &k3);
								switch (k3){
									case 1:{
										float a, b;
										printf("Ham bac 1: ax = b\n");
										printf("Nhap he so a, b: "); scanf("%f%f",&a, &b);
										if(a ==0 && b != 0)
											printf("Phuong trinh vo nghiem.\n");
										else
										if(a == 0 && b == 0)
											printf("Phuong trinh vo so nghiem.\n");
										else
											printf("Phuong trinh co nghiem x = %0.2f\n", b/a);
										break;
									}
									case 2:{
										float a, b, c, x1, x2;
										printf("Ham bac 2: ax^2 + bx + c = 0\n");
										printf("Nhap he so a, b, c: "); scanf("%f%f%f",&a, &b, &c);
										if(a== 0 && a== b && a == c){
											printf("Phuong trinh vo so nghiem.\n");
										}else
										if(a == 0 && b == 0 && c!= 0){
											printf("Phuong trinh vo nghiem.\n");
										}else
										if(a == 0 && b != 0 ){
											printf("Phuong trinh co nghiem duy nhat x = %0.2f\n", -1*c/b);
										}else
										if(c == 0 ){
											printf("Phuong trinh co 2 nghiem: \n\t\t\t + x = 0 \n\t\t\t + x = %f\n", -1*b/a);
										}else{
											float denta = b*b - 4*a*c;
											if(denta == 0){
												printf("Phuong trinh co nghiem kep: x = %0.2f\n", -0.5*b/a);
											}else 
											if(denta > 0){
												x1 = (-1*b + sqrt(denta))/(2*a);
												x2 = (-1*b - sqrt(denta))/(2*a);
												printf("Phuong trinh co 2 nghiem: \n\t\t\t + x1 = %0.2f \n\t\t\t + x2 = %0.2f\n", x1, x2);
											} else
											if(denta < 0)
												printf("Phuong trinh vo nghiem.\n");
										}	
										break;
									}
								}
							printf("\n\n");
							}while(k3 != 0);
							break;
						}
						case 2:{
						int d;
						int a[100];
						printf("Nhap khong gian Pn: "); scanf("%d", &d);
						int i;
						for(i=0; i<=d; i++){
							printf("Nhap he so cua x^%d: ", i);
							scanf("%d", &a[i]);
						}
						int k; printf("Dao ham cap: "); scanf("%d", &k);
						Daoham(a, &d, k);
						for(i=d; i>=0; i--)
							if(i != 0)
								printf("\t %dx^%d + ", a[i], i);
							else
							if(i == 1)
								printf("\t %dx + ", a[i]);
							else
								printf("\t %d\n", a[i]);
						int x, p=0;
						printf("Nhap gia tri x0 = ");  scanf("%d", &x);
						for(i=d; i>=0; i--)
						 p += a[i]*pow(x, i);
						 printf("Dao ham cap %d cua P(x) tai x = %d la: %d", k, x, p);
						break;
					}
						case 3:{
						char a[100];
						printf("Nhap so a: "); scanf("%s", a); XoaXuongDong(a);
						char b[100];
						printf("Nhap so b: "); scanf("%s", b); XoaXuongDong(b);
						char c[100], x[100], y[100], d[100];
						if(a[0] != '-' && b[0] != '-'){
							Tongab(a, b, c); printf("%s + %s = %s\n", a, b, c);
							Hieuab(a, b, c); printf("%s - %s = %s\n", a, b, c);
							Tichab(a, b, c); printf("%s . %s = %s\n", a, b, c);
							Thuongab(a, b, c, d); 	
							if(SS(d, "0") != 2) printf("%s  /  %s = %s du %s \n", a, b, c, d);
							else printf("%s  /  %s = %s\n", a, b, c);
						}else
						if((a[0] == '-' && b[0] != '-') || (a[0] != '-' && b[0] == '-')){
							if(a[0] == '-' && b[0] != '-'){
								char x[100];
								strcpy(x, a+1);
								Hieuab(b,x, c); 
								printf("(%s)  +  %s = %s\n", a, b, c);
								Tongab(x, b, c); strcpy(c+1, c); c[0] = '-';
								printf("(%s)  -  %s = %s\n", a, b, c);
								Tichab(x, b, c); 
								printf("(%s)  x  %s = -%s\n", a, b, c);
								Thuongab(x, b, c, d); 
								if(SS(d, "0") != 2)	printf("(%s)  /  %s = -%s du -%s \n", a, b, c, d);
								else printf("(%s)  /  %s = -%s \n", a, b, c);
							}else{
								char x[100];
								strcpy(x, b+1);
								Hieuab(a,x, c); 
								printf("%s  +  (%s) = %s\n", a, b, c);
								Tongab(a, x, c);
								printf("%s  -  (%s) = %s\n", a, b, c);
								Tichab(a, x, c); 
								printf("%s  x  (%s) = -%s\n", a, b, c);
								Thuongab(a, x, c, d); 	
								if(SS(d, "0") != 2) printf("%s  /  (%s) = -%s du -%s \n", a, b, c, d);
								else printf("%s  /  (%s) = -%s \n", a, b, c);
							}
						
						}else{
							char y[100], x[100];
							strcpy(x, a+1);
							strcpy(y, b+1);
							Tongab(x, y, c); strcpy(c+1, c); c[0] = '-';
							printf("(%s) + (%s) = %s\n", a, b, c);
							Hieuab(y, x, c); 
							printf("(%s) - (%s) = %s\n", a, b, c);
							Tichab(x, y, c); printf("(%s).(%s) = %s\n", a, b, c);
							Thuongab(a, b, c, d); 
							if(SS(d, "0") != 2)	printf("(%s)  /  (%s) = %s du %s \n", a, b, c, d);
							else printf("(%s)  /  (%s) = %s \n", a, b, c);
						}
						break;
					}
						case 4:{
						printf("\n 2.4.1 Cap so cong. \n 2.4.2 Cap so nhan.\n 2.4.0 Thoat.\n");
						int k3; printf("Lua chon: "); scanf("%d", &k3);
						switch (k3){
							case 1:{
								int d, u;
								printf("Nhap u0 va cong sai(d): "); scanf("%d%d", &u, &d);
								int x;
								printf("Tim so hang thu: "); scanf("%d", &x);
								printf("So hang thu %d la: %d\n", x, u + (x-1)*d);
								printf("Tong %d so hang dau tien la: %0.2f\n", x, (float) (2*u + x*d - d)*x/2);
								break;
							}
							case 2:{
								int u, p;
								printf("Nhap u0 va cong boi(p): "); scanf("%d%d", &u, &p);
								int x;
								printf("Tim so hang thu: "); scanf("%d", &x);
								printf("So hang thu %d la: %0.2f\n", x, u*pow(p, x-1));
								printf("Tong %d so hang dau tien la: %0.2f\n", x, (float) u*(1 - pow(p, x))/(1- p));
								break;
							}
						}while(k3 != 0);
						break;
						}
						case 5:{
							SP a, b, c;
							printf("\n Chuc nang so phuc: \n\t\t 2.5.1 Tong 2 so phuc.\n\t\t 2.5.2 Hieu 2 so phuc.\n\t\t 2.5.3 Modun so phuc.\n\t\t 2.5.4 Tich 2 so phuc.\n\t\t 2.5.5 Thuong 2 so phuc.\n\t\t 2.5.6. So phuc lien hop.\n\t\t 2.5.0 Thoat.\n Su dung chuc nang: ");
							int k3;	scanf("%d", &k3);
							switch (k3){
								case 1:{
									printf("\nTong 2 so phuc");
									NhapSP(&a);
								    NhapSP(&b);
									c = TongSP(a, b);	
									XuatSP(a); printf("\t+\t"); XuatSP(b); printf("\t=\t"); XuatSP(c);
									break;
								}
								case 2:{
									printf("\nHieu 2 so phuc");
									NhapSP(&a);
								    NhapSP(&b);
									c = HieuSP(a, b);	
									XuatSP(a); printf("\t-\t"); XuatSP(b); printf("\t=\t"); XuatSP(c);
									break;
								}
								case 3:{
									printf("\nModun so phuc");
									NhapSP(&a);	
									printf("Mo dun cua ");	XuatSP(a); printf(" la: %0.2f\n", Modun(a));
									break;
								}
								case 4:{
									printf("\nTich 2 so phuc");
									NhapSP(&a);
								    NhapSP(&b);
									c = TichSP(a, b);	
									XuatSP(a); printf("\t.\t"); XuatSP(b); printf("\t=\t"); XuatSP(c);
									break;
								}
								case 5:{
									printf("\nThuong 2 so phuc");
									NhapSP(&a);
								    NhapSP(&b);
									c = ThuongSP(a, b);	
									XuatSP(a); printf("\t/\t"); XuatSP(b); printf("\t=\t"); XuatSP(c);
									break;
								}
								case 6:{
									printf("\nModun so phuc");
									NhapSP(&a);	
									c = LienHopSP(a);
									printf("So phuc lien hop cua ");	XuatSP(a); printf(" la: "); XuatSP(c);
									break;
								}
							}while(k3 != 0);
							break;
						}
						case 6:{
						printf("\n Chuc nang phan so: \n\t\t 2.6.1 Tong 2 phan so.\n\t\t 2.6.2 Hieu 2 phan so.\n\t\t 2.6.3 Tri tuyet doi.\n\t\t 2.6.4 Tich 2 phan so.\n\t\t 2.6.5 Thuong 2 phan so.\n\t\t 2.6.6. Nghich dao.\n\t\t 2.6.0 Thoat.\n Su dung chuc nang: ");
							int k3;	scanf("%d", &k3);
							switch (k3){
								PS a, b, c;
								case 1:{
									printf("Tong 2 phan so.\n");
									NhapPS(&a);
									NhapPS(&b);
									c = TongPS(a, b);
									XuatPS(a); printf("\t+\t"); XuatPS(b); printf("\t=\t"); XuatPS(c);
									break;
								}
								case 2:{
									printf("Hieu 2 phan so.\n");
									NhapPS(&a);
									NhapPS(&b);
									c = HieuPS(a, b);
									XuatPS(a); printf("\t-\t"); XuatPS(b); printf("\t=\t"); XuatPS(c);
									break;
								}	
								case 3:{
									printf("Tri tuyet doi.\n");
									NhapPS(&a);
									TriTuyetDoiPS(&a);
									XuatPS(a);
									break;
								}
								case 4:{
									printf("Tich 2 phan so.\n");
									NhapPS(&a);
									NhapPS(&b);
									c = TichPS(a, b);
									XuatPS(a); printf("\t.\t"); XuatPS(b); printf("\t=\t"); XuatPS(c);
									break;
								}
								case 5:{
									printf("Thuong 2 phan so.\n");
									NhapPS(&a);
									NhapPS(&b);
									c = ThuongPS(a, b);
									XuatPS(a); printf("\t/\t"); XuatPS(b); printf("\t=\t"); XuatPS(c);
									break;
								}
								case 6:{
									printf("Nghich dao.\n");
									NhapPS(&a);
									c = NghichDaoPS(a);
									XuatPS(c);
									break;
								}
							}	while(k3 != 0);
						break;
					}
					}
				printf("\n\n");
				}while(k2 != 0);
				printf("\n\n");
				break;
			}
			case 3: {
				int k2;
				do{
					printf("Chao mung den voi Mot so bai toan ve day so!\nChung toi co cac chuc nang sau:\n");
						printf("\n\t 3.1. Day so fibonaci. \n\t 3.2 Day so nguyen to. \n\t 3.3 Day so chinh phuong. \n\t 3.4 Kiem tra so dep.\n\t 3.0 Thoat.\n");
					printf("Su dung chuc nang: ");	scanf("%d", &k2);
					switch (k2){
						case 1:{
							printf("Day fibonaci: la day co u1 = u2 = 1, u3 = u2 + u1, u(n) = u(n-1) + u(n-2).\n");
							int n1; printf("Nhap so so luong: "); scanf("%d", &n1);
							int i = 1;
							int x[3];
							x[1] = 1;
							x[2] = 1;
							while (i != n1 + 1){
								if(i == 1 || i == 2){
									printf("1 ");
									i++;
								}else{
									x[3] = x[1] + x[2];
									printf("%d ", x[3]);
									x[1] = x[2];
									x[2] = x[3];
									i++;
								}
							}
							break;
						}
						case 2:{
							printf("Day so nguyen to.\n");
							int n1; printf("Nhap so so luong: "); scanf("%d", &n1);
							int i = 2, n2 =0;
							while( n2 != n1){
								if(KTNT(i) == 1){
									printf("%d ", i);
									n2++;
								}
								i++;
							}
							break;
						}
						case 3:{
							printf("Day chinh phuong.");
							int n1; printf("\nNhap so luong: "); scanf("%d", &n1);
							int i;
							for(i=1; i<=n1; i++)
								printf("%d ",(int) pow(i, 2));
							break;
						}
						case 4:{
							printf("Kiem tra so dep: la so co tong cac uoc(k tinh no) bang chinh no.\n");
							int n1; printf("So can kiem tra: "); scanf("%d", &n1);
							if(KTSD(n1) == 1)
							printf("%d la so dep.", n1);
							else
							printf("%d k la so dep.", n1);
							break;
						}
					}
					printf("\n\n");
				}while(k2 != 0);
				printf("\n\n");
				break;
			}
			case 4: {
			int k2;
			do{
			printf("Chuc nang ve hinh: \n\t\t 4.1 Ve tam giac can(Theo chieu cao). \n\t\t 4.2 Ve Tam giac vuong can. \n\t\t 4.3 Ve hinh thoi(Do dai 2 duong cheo la so le). \n\t\t 4.4 Hinh chiec no(co chieu cao h). \n\t\t 4.5 Hinh canh dieu. \n\t\t 4.6 Ve cay thong. \n\t\t 4. \n\t\t 4. \n\t\t 4. \n\t\t 4.0 Thoat. \n");
			printf("Ban su dung chuc nang: "); scanf("%d", &k2);
			switch (k2){
				case 1:{
					int h; printf("Ve tam giac can.\nNhap chieu cao h: "); scanf("%d", &h);
					int i, j;
					for(i=0; i<h + 1; i++){
						for(j=0; j<2*h + 1; j++){
							if(j >= h - i && j<= h+i)
								printf(" * ");
							else
								printf("   ");
						}
					printf("\n");
					}
					break;
				}
				case 2:{
					int h;
					printf("Ve tam giac vuong.\n Nhap do dai canh: "); scanf("%d", &h);
					int i, j;
					for(i=0; i<2*h + 1; i++){
						for(j=0; j<2*h + 1; j++)
							if(j<=i)
								printf(" * ");
							else
								printf("   ");
						printf("\n");
					}
					break;
				}
				case 3:{
					int h; printf("Ve hinh thoi.\nNhap chieu cao h: "); scanf("%d", &h);
					int i, j;
					for(i=0; i<=h; i++){
						for(j=0; j<2*h + 1; j++)
								if(j >= h -i && j<= h + i)
									printf(" * ");
								else
									printf("   ");
						printf("\n");	
					}
					for(i=0; i<=h; i++){
						for(j=0; j<2*h + 1; j++)
							if(j>i && j< 2*h - i)
								printf(" * ");
							else
								printf("   ");
						printf("\n");	
					}
					break;
				}
				case 4:{
					int h; printf("Ve hinh chiec no.\nNhap chieu cao h: "); scanf("%d", &h);
					int i, j;
					for(i=0; i<=h; i++){
						for(j=0; j<2*h + 1; j++)
							if(j<=i || j>= 2*h - i)
								printf(" * ");
							else
								printf("   ");
						printf("\n");
					}
					for(i=0; i<2*h + 1; i++){
						for(j=0; j<2*h + 1; j++)
							if(j < h-i || j > h+i)
								printf(" * ");
							else
								printf("   ");
						printf("\n");
					}
					break;
				}
				case 5:{
					int h; printf("Ve hinh canh dieu.\nNhap chieu cao h: "); scanf("%d", &h);
					int i, j;
					for(i=0; i<=h; i++){
						for(j=0; j<2*h+1; j++)
							if(i == h || j == h - i || j == h || j == h +i)
								printf(" * ");
							else
								printf("   ");
						printf("\n");
					}
					for(i=1; i<=h; i++){
						for(j=0; j<= 2*h; j++)
							if(j == h || j == i || j == 2*h - i)
								printf(" * ");
							else
								printf("   ");
						printf("\n");
					}
					break;
				}
				case 6:{
					int h; printf("Ve hinh cay thong.\nNhap chieu cao h: "); scanf("%d", &h);
					int i, j, d = (2*h +1)/3;
					for(i=0; i<=d; i++){
						for(j=0; j<2*h + 1; j++)
							if(j>= h -i && j <= h+i)
								printf(" * ");
							else
								printf("   ");
						printf("\n");
					}
					for(i=0; i<=d; i++){
						for(j=0; j<=2*h; j++)
							if(j>= h - d/2 - i && j <= h + d/2 + i)
								printf(" * ");
							else
								printf("   ");
						printf("\n");
					}
					for(i=0; i<=d/2; i++){
						for(j=0; j<=2*h; j++)
							if(j>= h - d/2 && j <= h + d/2)
								printf(" * ");
							else
								printf("   ");
						printf("\n");
					}
					break;
				}
			}
			printf("\n\n");
			}while(k2 != 0);
			break;
		}
		}
		printf("\n\n");
	}while (k1 != 0);
}



















