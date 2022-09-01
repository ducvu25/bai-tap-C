
/*#include <stdio.h>
#include <string.h>

typedef struct {
	int STT;
	char Name[30];
	char MSV[9];
	float diem1, diem2, diem3, diem4;
	float diemTB;
	long HB;	
}TT;
void Nhap(TT *a){
	printf("Nhap STT: "); scanf("%d", &a->STT);
	printf("Nhap ho va ten: "); fflush(stdin); fgets(a->Name, sizeof(a->Name), stdin);
	if(a->Name[strlen(a->Name) - 1] == '\n')
		a->Name[strlen(a->Name) - 1] = '\0';
	printf("Nhap MSV: "); scanf("%s", a->MSV);
	printf("Nhap diem cac mon thi 1: "); scanf("%f", &a->diem1);
	printf("Nhap diem cac mon thi 2: "); scanf("%f", &a->diem2);
	printf("Nhap diem cac mon thi 3: "); scanf("%f", &a->diem3);
	printf("Nhap diem cac mon thi 4: "); scanf("%f", &a->diem4);
	a->diemTB = (a->diem1*2 + a->diem2*3 + a->diem3*2 + a->diem4*3)/10;
	if(a->diemTB >= 9 && a->diem1 >= 8.5)	a->HB = 1200000;
	else	if(a->diemTB < 9 && a->diemTB >= 8)	a->HB = 1000000;
	else	if(a->diemTB >= 7.5)	a->HB = 800000;
	else	a->HB = 0;
}
int main(){
	int t, i;
	printf("Nhap sl: ");	scanf("%d", &t);
		FILE *fp;
	fp = fopen("D:\\C\\Test.txt", "a");
	while(t > 0){
		TT a;
		printf("Nhap ban nghi thu %d:\n", i + 1);
		Nhap(&a);
		fprintf(fp, "%d \n%s \n%0.2f \n%0.2f \n%0.2f \n%0.2f \n%0.2f \n%ld\n", a.STT, a.MSV, a.diem1, a.diem2, a.diem3, a.diem4, a.diemTB, a.HB);
		t--;
	}
	fclose(fp);
	
	
	
}

#include <stdio.h>
#include <string.h>

typedef struct {
	int STT;
	char Name[30];
	char MSV[9];
	float diem1, diem2, diem3, diem4;
	float diemTB;
	long HB;	
}TT;
TT Nhap(){
	TT a;
	printf("Nhap STT: "); scanf("%d", &a.STT);
	printf("Nhap ho va ten: "); fflush(stdin); fgets(a.Name, sizeof(a.Name), stdin);
	if(a.Name[strlen(a.Name) - 1] == '\n')
		a.Name[strlen(a.Name) - 1] = '\0';
	printf("Nhap MSV: "); scanf("%s", a.MSV);
	printf("Nhap diem cac mon thi 1: "); scanf("%f", &a.diem1);
	printf("Nhap diem cac mon thi 2: "); scanf("%f", &a.diem2);
	printf("Nhap diem cac mon thi 3: "); scanf("%f", &a.diem3);
	printf("Nhap diem cac mon thi 4: "); scanf("%f", &a.diem4);
	a.diemTB = (a.diem1*2 + a.diem2*3 + a.diem3*2 + a.diem4*3)/10;
	if(a.diemTB >= 9 && a.diem1 >= 8.5)	a.HB = 1200000;
	else	if(a.diemTB < 9 && a.diemTB >= 8)	a.HB = 1000000;
	else	if(a.diemTB >= 7.5)	a.HB = 800000;
	else	a.HB = 0;
	return a;
}
int main(){
	int sl, i;
	printf("Nhap sl: ");	scanf("%d", &sl);
		FILE *fb;
	fb = fopen("D:\\C\\Test.txt", "a");
	for(i=0; i<sl; i++){
		TT a;
		printf("Nhap ban nghi thu %d:\n", i + 1);
		a = Nhap();
		fprintf(fb, "%d\n", a.STT);
		fprintf(fb, "%s\n", a.Name);
		fprintf(fb, "%s\n", a.MSV);
		fprintf(fb, "%0.2f\n", a.diem1);
		fprintf(fb, "%0.2f\n", a.diem2);
		fprintf(fb, "%0.2f\n", a.diem3);
		fprintf(fb, "%0.2f\n", a.diem4);
		fprintf(fb, "%0.2f\n", a.diemTB);
		fprintf(fb, "%ld\n", a.HB);
	}
	fclose(fb);
	
	
	
}

#include <stdio.h>
void yA(int a[][100], int m, int n){
	int i, j;
	int Tong = 0, sl = 0;
	for(j=1; j<n; j+= 2){
		int max = -1;
		sl++;
		for(i=0; i<m; i++)
			max = max > a[i][j] ? max : a[i][j];
		Tong += max;
	}
	printf("Trung binh cong cac gia tri lon nha tren cot chan la: %0.2f\n", (float) Tong/sl);
}
void yB(int a[][100], int m, int n){
	long Tich = 1;
	int i, j;
	for(i=0; i<m; i++) {
		for(j=0; j<n; j++){
			if((a[i][j] > 1 && a[i][j] < 11) || (a[i][j] > 19 && a[i][j] < 51))
				Tich *= a[i][j];
			}
		}
	printf("Tich cac phan tu thoa man yeu cau: %d", Tich);
}
int main(){
	int m, n, i, j;
	scanf("%d%d", &m, &n);
	int a[100][100];
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			scanf("%d", &a[i][j]);
	
	yA(a, m, n);
	yB(a, m, n);
return 0;
}
*/
#include <stdio.h>
#include <string.h>
typedef struct {
	char TCH[50];
	char LH[20];
	int CSD;
	int CSC;
	long DonGia;
	long TT;
}BanGhi;
void XoaEnter(char *s){
	if(s[strlen(s) - 1] == '\n')
		s[strlen(s) - 1] = '\0';
}
BanGhi NhapTT(){
	BanGhi x;
	printf("Nhap ten chu ho: "); 
	fflush(stdin); 
	fgets(x.TCH, sizeof(x.TCH), stdin);	XoaEnter(x.TCH);
	printf("Nhap loai ho: ");
	fgets(x.LH, sizeof(x.LH), stdin);	XoaEnter(x.LH);
	printf("Nhap chi so dau: "); scanf("%d", &x.CSD);
	printf("Nhap chi so cuoi: "); scanf("%d", &x.CSC);
	if(x.CSC - x.CSD <= 50)
		x.TT = (x.CSC - x.CSD)*700;
	else if(x.CSC - x.CSD <= 150)
		x.TT = 50*700 + (x.CSC - x.CSD - 50)*1000;
	else
		x.TT = 50*700 + 100*1000 + (x.CSC - x.CSD - 150)*200;
		
	if(strcmp(x.LH, "Gia dinh") == 0)
		x.TT += 50000;
	else	if(strcmp(x.LH, "Kinh doanh") == 0)	
		x.TT += 60000;
	else
		x.TT += 55000;
	return x;
}
int main(){
	int q;
	printf("Nhap so luong ban ghi: "); scanf("%d", &q);
	BanGhi a[q];
	int i;
	for(i=0; i<q; i++)
		a[i] = NhapTT();
	FILE *file;
	file = fopen("D:\\TienDien", "a");
//	file = fopen("D:\\C\\Test.txt", "a");
	for(i=0; i<q; i++){
		fprintf(file, "%s\n", a[i].TCH);
		fprintf(file, "%s\n", a[i].LH);
		fprintf(file, "%d\n", a[i].CSD);
		fprintf(file, "%d\n", a[i].CSC);
		fprintf(file, "%ld\n", a[i].TT);
	}
	
}
