/* Chuyen co so 10 sang he co so bat ki va nguoc lai
// C1:
#include <stdio.h>
#include <math.h>
#include <string.h>

void ChuyenXuoi(int n, char a[100], int m){
	int x = log(n)/log(m), len = x;
	int i;
	char b[100];
	for(i=0; i<=x; i++)
		b[i] = 48;
	while (n != 0){
		int denta = 48;
		b[x] = n/pow(m, x);
		if(b[x] > 9)  denta = 55;
		else 	denta = 48;
		b[x] += denta;
		n -= (b[x] -denta)*pow(m, x);
		x = log(n)/log(m);
	}
	for(i=len; i>=0; i--)
		a[len-i] = b[i];
}

void ChuyenNguoc(int *n, char a[100], int x){
	int m = 0, i, denta = 48;
	for(i=strlen(a)-1; i>=0; i--){
		if(a[i] >= 65 )  denta = 55;
		else denta = 48;
		m += (a[i] - denta)*pow(x, strlen(a)-1 - i);
		printf("\n%d =  %d*%d",m,  a[i], pow(x, strlen(a)- 1 - i));
	}
	*n = m;
}
int main(){
	int n; 	printf("Nhap n: ");	scanf("%d", &n);
	char a[100];
	int x;	printf("\nChuyen sang co so: ");	scanf("%d", &x);
	ChuyenXuoi(n, a, x);
	printf("\n%s\n", a);
	ChuyenNguoc(&n, a, x);
	printf("Ta duoc: %d", n);
}


// C2:
 
#include <stdio.h>
#include <string.h>

void Chuyendoi(int a, int b, char c[100]){
	int i = 0, d, x = a;
	while(x != 0){
		d = x%b;
		if(d >9){
			c[i] = d + 55;
			i++;
		}else{
			c[i] = d + 48;
			i++;
		}
		x /= b;
	}
	strrev(c);
}

int main(){
	int n;	printf("Nhap so luong test: ");	scanf("%d", &n);
	int i;
	for(i=0; i<n; i++){
		int a;	printf("Nhap so can chuyen: ");	scanf("%d", &a);
		int b;	printf("Nhap co so can chuyen: ");	scanf("%d", &b);
		char c[100];	Chuyendoi(a, b, c);
		printf("So %d chuyen sang co so %d la: %s\n", a, b, c);
	}
}
*/

/* Dem so tu trong 1 cau;
#include <stdio.h>
#include <string.h>

int Sotu(char a[100]){
	a[strlen(a)] = 32;
	int i, count =0;
	for(i=0; i<strlen(a); i++)
		if(a[i] != a[i+1] && a[i+1] == 32)
			count++;
	return count;
}

int main(){
	char a[1000];
	fgets(a, sizeof(a), stdin);
	printf("%s", a);
	char c = 0;
	printf("\n ki tu %d", Sotu(a));
}
*/

/* Viet ham kiem tra so thuan nghich su dung xau roi hien thi cac so co 9 chu so thoa man
#include <stdio.h>
#include <string.h>

void Chuyendoi(int n, char a[100]){
	
}
void Tangn(char a[100], int n){
	if(a[n] == 48 +9)	{
		Tangn(a, n-1);
		a[n] = 48;
	}
	else	a[n]++;
}
int Kt(char a[100]){
	int i;
	for(i=0; i<=strlen(a)/2; i++)
		if(a[i] != a[strlen(a) - 1 -i]) return 0;
	return 1;
}
int KT(char a[100], char b[100]){
	int i;
	for(i=0; i<strlen(a); i++)
		if(a[i] != b[i])	return 0;
	return 1;
}

int main(){
	char a[] = "100000001";
	char b[] = "999999999";
	while(KT(a, b) == 0){
		if(Kt(a) == 1)		printf("\n%s", a);
		Tangn(a, 8);
	} 	
}
*/

/* thuc hien viet hoa ca cau, in thuong ca cau
#include <stdio.h>
#include <string.h>

void inHoa(char a[100]){
	int i;
	for(i=0; i<strlen(a)-1; i++)
		if(a[i] >= 97 && a[i] <= 122) 	a[i] -= 32;
}

void inThuong(char a[100]){
	int i;
	for(i=0; i<strlen(a)-1; i++)
		if(a[i] >= 65 && a[i] <= 90) 	a[i] += 32;
}

int main(){
	char a[1000];
	fgets(a, sizeof(a), stdin);
	inHoa(a);
	printf("\n%s", a);
	inThuong(a);
	printf("\n%s", a);
}
*/

/* Dem so lan xuat hien : co phan biet hoa thuong, khong phan biet hoa thuong
#include <stdio.h>
#include <string.h>

int SL(char a[100], char x, int d){
	int i, count = 0;
	if(x == 32) return 0;
	if(d==1){
		for(i=0; i<strlen(a)-1; i++)
			if(a[i]==x)	count ++; 
	} else
		for(i=0; i<strlen(a)-1; i++)
			if(a[i]==x || (a[i] - 32) == x || (a[i] +32) ==x)	count ++; 
	return count;
}
int Xuathien(char a[100], char x, int n, int d){
	int i;
	if(d==1){
		for(i=0; i<n; i++)
			if(a[i]==x)	return 0;
	} else
		for(i=0; i<n; i++)
			if(a[i]==x || (a[i] - 32) == x|| (a[i] +32) ==x)	return 0;
	return 1;
}

int main(){
	char a[100];
	fgets(a, sizeof(a), stdin);
	int i;
	printf("Phan biet in hoa in thuong:");
	for(i=0; i<strlen(a)-1; i++)
		if(SL(a, a[i], 1) >0 && Xuathien(a, a[i], i, 1) == 1) 
			printf("\n%c xuat hien: %d", a[i], SL(a, a[i], 1));
			
	printf("\nKhong phan biet in hoa in thuong:");
	for(i=0; i<strlen(a)-1; i++)
		if(SL(a, a[i], 0) >0 && Xuathien(a, a[i], i, 0) == 1) 
			printf("\n%c xuat hien: %d", a[i], SL(a, a[i], 0));
}
*/

/* Chuan hoa xau ki tu ( xoa dau cach thua, in hoa chu cai dau cua tung tu, cac ki tu khac thanh in thuong)
#include <stdio.h>
#include <string.h>

 void ChuanHoa(char a[100]){
 	int i;
 	for(i=0; i<strlen(a)-2; i++){
 		if(a[i] == a[i+1] && a[i] == 32) {
 			strcpy(a+i,a+i+1);
 			i--;
		 }
 		if(a[0] >= 97 && a[0] <= 122)
 			a[0] -= 32;
 		if(a[i] != a[i+1] && a[i] == 32 && a[i+1]>= 97 && a[i+1] <= 122)	
 			a[i+1] -= 32;
 		if(a[i] != 32 && a[i+1] >= 65 && a[i+1] <= 90 )
 			a[i+1] += 32;
	 }
 	
 }
 int main(){
 	char a[1000];
 	fgets(a, sizeof(a), stdin);
 	printf("\nTruoc: %s", a);
 	ChuanHoa(a);
 	printf("\nSau: %s", a);
 	
 }
 */
 
/* Nhap xau ki tu in ra tu dai nhat

#include <stdio.h>
#include <string.h>

void KiTuMax(char a[100], char b[100], int *d){
	a[strlen(a)-1] = 32;
	int k =0, x, i, max =0, count =0;
	for(i=0; i<strlen(a)-1; i++)
		if(a[i] != a[i+1] && a[i+1] == 32){
			x = i + 1 - k;
			count++;
			if (x > max){
				max =x;
				strncpy(b, a + k, x);
				*d = count;
				printf("\n%s", b);
			}
			k = i + 2;
		}
}

int main(){
	char a[1000];
 	fgets(a, sizeof(a), stdin);
 	char b[100];
 	int d;
 	KiTuMax(a, b, &d);
 	printf("\nKi tu dai nhat la: %s - tu so: %d", b, d);
}
*/

/* nhap ho ten: ho- dem- ten chuyen thanh ten- dem- ho

#include <stdio.h>
#include <string.h>

void ChuyenDoi(char a[100]){
	char b[100][100];
	int i, k=0, count =0;
	a[strlen(a)-1] = 32;
	for(i=0; i<strlen(a)-1; i++)
		if(a[i] != a[i+1] && a[i+1] == 32){
			strncpy(b[count], a + k, i + 2 - k);
			k = i + 2;
			printf("\n%s", b[count]);
			count++;
		}
	for(i=count-1; i>=0; i--)
		if(i== count -1)	strcpy(a, b[i]);
		else	strcat(a, b[i]);
}

int main(){
	char a[100];
	fgets(a, sizeof(a), stdin);
	printf("\nTruoc: %s", a);
	ChuyenDoi(a);
	printf("\nSau: %s", a);
}

*/

/* Nhap xau ki tu cho biet bao nhieu nguyen am, phu am, ki tu so, ki tu dac biet;

#include <stdio.h>
#include <string.h>

void XoaXuongDong(char a[100]){
	if(a[strlen(a)-1] == '\n')
		a[strlen(a)-1] = '\0';
}

void ThongTin(char a[100], int *n, int *p, int *s, int *d){
	char b[] = "ueoai";
	int i, x =0, y=0, z=0, t =0;
	for(i=0; i<strlen(a)-1; i++)
		if(strchr(b, a[i]) != 0)	x++;
		else
		if(a[i] >= 48 && a[i] <= 57)	z++;
		else
		if((a[i] >= 65 && a[i] <= 90) || (a[i] >= 97 && a[i] <= 122)) y++;
		else
		if(a[i] != 32) 	t++;		
	*n = x;
	*p = y;
	*s = z;
	*d = t;
}

int main(){
	char a[100];	fgets(a, sizeof(a), stdin);	XoaXuongDong(a);
	int n, p, s, d;
	ThongTin(a, &n, &p, &s, &d);
	printf("\nXau %s co: \n\t+ %d nguyen am. \n\t+ %d phu am. \n\t+ %d ki tu so. \n\t+ %d ki tu dac biet", a, n, p, s, d);
}
*/

/* tach cac tu ra roi sap xep theo bang chu cai

#include <stdio.h>
#include <string.h>

void Tach(char a[100], char b[100][100]){
	int i, j, k=0, count =0;
	a[strlen(a) -1] = 32;
	for(i=0; i<strlen(a)-1; i++)
		if(a[i] != a[i+1] && a[i+1] == 32){
			strncpy(b[count], a + k, i + 1 - k);
			count++;
			k = i +2;
		}
	for(i=0; i<count-1; i++)
	 for(j=i+1; j<count; j++)
	 	if(b[i][0] >b[j][0]){
	 		char t[100];
	 		strcpy(t, b[i]);
	 		strcpy(b[i], b[j]);
	 		strcpy(b[j], t);
		 }
	for(i=0; i<count; i++)
			printf("\n%s", b[i]);
}
int main(){
	char a[100];	fgets(a, sizeof(a), stdin);
	char b[100][100];	Tach(a, b);
}
 */
 
 /* Thay the s1 boi s2 trong xau s, loai bo s1 trong s
 
 #include <stdio.h>
 #include <string.h>
 void XoaXuongDong(char a[100]){
 	if(a[strlen(a) -1] == '\n')
 		a[strlen(a) - 1] = '\0';
 }
 void ThayThe(char a[100], char x[100], char y[100]){
 	char *p;
 	char b[100];
 	p = strstr(a, x);
 	strcpy(b, p + strlen(x));
 	strncpy(p, y, strlen(y));
 	strcpy(p + strlen(y) , b);
 }
 void Loai(char a[100], char x[100]){
 	char *p;
 	p = strstr(a, x);
 	strcpy(p, p + strlen(x)+1);
 }
 int main(){
 	char a[100];	printf("Nhap xau: ");	fgets(a, sizeof(a), stdin);	XoaXuongDong(a);
 	char x[100];		printf("Nhap xa s1: ");	fgets(x, sizeof(x), stdin);	XoaXuongDong(x);
 	char y[100];		printf("Nhap xa s2: ");	fgets(y, sizeof(y), stdin);	XoaXuongDong(y);
 	ThayThe(a, x, y);
 	printf("\nSau : %s", a);
 	Loai(a, y);
 	printf("\nSau : %s", a);
 }
*/

/* Tinh tong , hieu, tich 2 so lon

#include <stdio.h>
#include <string.h>

void Xoa0(char a[100]){
	while(a[0] == '0' && strlen(a) > 1){
		strcpy(a, a+1);
	}
}
void StrRev(char a[100], char b[100]){
	strrev(a);
	strrev(b);
}
void  SS(char a[100], char b[100], char x[100], char y[100], int *d){
	if(strlen(a) > strlen(b)){
		strcpy(x,a);
		strcpy(y,b);
		*d =1;
	}else
	if(strlen(a) < strlen(b)){
		strcpy(x,b);
		strcpy(y,a);
		*d =0;
	}else{
		int i;
		for(i=0; i<strlen(a); i++)
			if(a[i] > b[i]) {
				strcpy(x,a);
				strcpy(y,b);
				*d =1;
			}else{
				strcpy(x,b);
				strcpy(y,a);
				*d =0;
			}
	}
	StrRev(x, y);
} // d ==1 <=> a > b, d ==0 <=> a < b;
void Tang(char a[100], int n){
	if(a[n] >= 10) {
		int d;
		d = a[n]/10;
		a[n+1] = d + 48;
		a[n] -= (d*10 - 48);
	}else{
		a[n] += 48; 
		a[n+1] = 48;
	}
}
void Tong(char a[100], char b[100], char c[100]){
	char x[100], y[100];
	int d, i;
	SS(a, b, x, y, &d);
	c[0] = x[0] - 48 + y[0] - 48 ;
	Tang(c, 0);
	for(i=1; i<strlen(x); i++){
		if(i<strlen(y)){
			c[i] += x[i] - 48 + y[i] - 48*2;
			Tang(c, i);
		}else{
			c[i] += x[i] - 48*2;
			Tang(c, i);
		}	
	}
	strrev(c);
	Xoa0(c);
} // k ==1 <=> a ==c , k ==0 <=> a !=c
void Giam(char a[100], int n){
	if(a[n] < 0){
		int d;
		d = (-1*a[n])/10;
		a[n] += (d+1)*10 + 48;
		a[n+1] = -d-1 + 48;
	}else{
		a[n] += 48;
		a[n+1] = 48;
	}
}
void Hieu(char a[100], char b[100], char c[100]){
	char x[100], y[100];
	int d, i;
	SS(a, b, x, y, &d);
	c[0] = x[0]  - y[0];
	Giam(c, 0);
	for(i=1; i<strlen(x); i++)
		if(i<strlen(y)){
			c[i] += x[i] - y[i] -48;
			Giam(c, i);
		}else{
			c[i] += x[i] - 48*2;
			Giam(c, i);
		}
	strrev(c);
	Xoa0(c);
	if(d==0 && c[0] != 48){
		strcpy(c+1, c);
		c[0] = '-';
	}	
}
void Tich1(char a[100], char b, char c[100]){
	char x[100];	strcpy(x, a);	strrev(x);
	c[0] = (x[0] -48)*(b - 48);
	Tang(c, 0);
	int i;
	for(i=1; i<strlen(x); i++){
		c[i] += (x[i] - 48)*(b-48) - 48;
		Tang(c, i);
	}
	strrev(c);
	Xoa0(c);
} // Tich voi 1 so
void Tich2(char a[100], char b[100], char c[100]){
	char t[100][100];
	char x[100], y[100], m[] = "0";
	int d, i;
	SS(a, b, x, y, &d);
	strrev(x);
	for(i=0; i<strlen(y); i++){
		for(d=0; d<i; d++)
			t[i][d] = 48;
		char z[] ="0";
		Tich1(x, y[i], z);
		strrev(z);
		strcpy(t[i] + i, z);
		strrev(t[i]);
		Tong(m, t[i], m);
	}
	strcpy(c, m);
}

int main(){
	char a[100];	printf("Nhap so a: ");	scanf("%s", a);
	char b[100];	printf("Nhap so b: ");	scanf("%s", b);
	char c[100];
	Tong(a, b, c);
	printf("\n %s + %s = %s", a, b, c);
	Hieu(a, b, c);
	printf("\n %s - %s = %s", a, b, c);
	Tich2(a, b, c);
	printf("\n %s x %s = %s", a, b, c);
}
*/


















