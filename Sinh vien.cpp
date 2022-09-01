/* sinh vien gom :
 + MSV : 4 so
 + Ho va ten
 + ngay sinh
 + gioi tinh
 + diem: toan ly hoa trung binh
 + hoc luc
 + hanh kiem
 thuc hien :
  + them moi sinh vien
  + hien thi danh sach sinh vien
  + sap xep theo ten
  + sap xep teo diem giam dan
  + ghi thong tin vao file 
  + doi ten sinh vien
  + viet menu
  */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void XoaXuongDong(char *a){
	if(a[strlen(a)-1] == '\n')
		a[strlen(a)-1] = '\0';
}
typedef struct ngaysinh{
	int d;
	int m;
	int y;
}Date;
typedef struct diem{
	float toan;
	float ly;
	float hoa;
	float TB;
}Diem;
typedef struct sinhvien{
	char MSV[5];
	char Name[50];
	Date Birthday;
	char Sex[5];
	Diem Marks;
	char Hocluc[20];
	int Rank;
	
}SV;
void ChuanHoa(char *a){
	if(a[0] <=122 && a[0] >= 95) a[0] -= 32;
	int i;
	for(i=1; i<strlen(a); i++){
		if(a[i] == 32 && a[i+1] >= 95 && a[i+1] <=122 ) a[i+1] -= 32;
		if(a[i] <=90 && a[i] >= 65 && a[i-1] != 32) a[i] += 32;
	}
}
SV Nhap(){
	SV a;
	printf("Nhap MSV: ");	scanf("%s", a.MSV);
	printf("Nhap ten: ");	fflush(stdin); fgets(a.Name, sizeof(a.Name), stdin);	ChuanHoa(a.Name);	XoaXuongDong(a.Name);
	printf("Nhap ngay sinh: ");	scanf("%d%d%d", &a.Birthday.d, &a.Birthday.m, &a.Birthday.y);
	printf("Nhap gioi tinh: ");	scanf("%s", a.Sex); ChuanHoa(a.Sex);
	printf("Nhap diem: "); scanf("%f%f%f", &a.Marks.toan, &a.Marks.ly, &a.Marks.hoa);
	a.Marks.TB = (a.Marks.toan + a.Marks.ly + a.Marks.hoa)/3;
	if(a.Marks.TB >= 9) {strcpy(a.Hocluc, "Gioi");
	}else
	if(a.Marks.TB >= 8){strcpy(a.Hocluc, "Kha");
	}else
	if(a.Marks.TB >= 6){strcpy(a.Hocluc, "Trung binh");
	}else			strcpy(a.Hocluc, "Yeu");
	return a;
}
void Xuat(SV a){
	printf("%-8s %-25s %-2d/%-2d/%-6d %-10s %-6.2f %-6.2f %-6.2f %-15.2f %-10s\n", a.MSV, a.Name, a.Birthday.d, a.Birthday.m, a.Birthday.y, a.Sex, a.Marks.toan, a.Marks.ly, a.Marks.hoa, a.Marks.TB, a.Hocluc );
}
int Login(){
	char TK[9];
	char MK[9];
	char c;
	int solan = 3;
	while(solan > 0){
		int soluong = 0;
		printf("\n\t\tDang nhap");
		printf("\n\tTK: "); scanf("%s", TK);
		printf("\n\tMK: "); 
		do{
			if(kbhit()){
				c = getch();
				if(c != 13){
					MK[soluong] = c;
					soluong++;
					printf("*");
				}else
					break;
			}
		}while(1);
		if(strcmp(TK, "Nhom7") == 0 && strcmp(MK, "nhom7") == 0)
			return 1;
		else{
			printf("\n\tSai tk hoac mk!");
			solan--;
			getch();
			system("cls");
		}
	}
	return 0;
}
void NhapDSSV(SV *a, int n){
	int i;
	for(i=0; i<n; i++){
		printf("Nhap sinh vien thu %d:\n", i);
		a[i] = Nhap();
	}
}
void XuatDSSV(SV *a, int n){
	printf("================================== DANH SACH SINH VIEN ======================================\n");
	printf("%-8s %-25s %-12s %-10s %-6s %-6s %-6s %-15s %-10s\n", "MSV", "Ho va Ten", "Ngay sinh", "Gioi tinh", "Toan", "Ly", "Hoa", "Trung binh", "Hoc luc");
	int i;
	for(i=0; i<n; i++)
		Xuat(a[i]);	
}
void Add(SV *a, int *n){
	int m = *n;
	m++;
	*n = m;
	a[m-1] = Nhap();
}
void Ten(SV a, char *c){
	int i;
	int len = strlen(a.Name);
	for(i=len-1; i>=0; i--){
		if(a.Name[i] == 32){
			strcpy(c, a.Name + i + 1);
			break;
		}
	}
}
void SwapName(SV* a, int n){
	int i, j;
	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++){
			char c[100];	Ten(a[i], c);
			char d[100];	Ten(a[j], d);
			if(strcmp(c, d) > 0){
				SV t ;
				t    = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
}
void SwapMarks(SV *a, int n){
	int i, j;
	SV b;
	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
			if(a[i].Marks.TB < a[j].Marks.TB){
				b = a[i];
				a[i] = a[j];
				a[j] = b;
			}
}

void Rank(SV *a, int n){
	SV *p;
	p = a;
	int i, j, r =1;
	SwapMarks(p, n);
	for(i=0; i<n; i++)
	 for(j=0; j<n; j++)
	  if(strcmp(a[j].MSV, p[i].MSV) == 0){
	  	if(i==0) a[j].Rank = 1;
	  	else if(p[i].Marks.TB == p[i-1].Marks.TB) 
		  			a[j].Rank = r;
		else {
			r++;
			a[j].Rank = r;
		}
	  }
	printf("====================================== DANH SACH SINH VIEN =============================================\n");
	printf("%-8s %-25s %-12s %-10s %-6s %-6s %-6s %-15s %-10s %-10s\n", "MSV", "Ho va Ten", "Ngay sinh", "Gioi tinh", "Toan", "Ly", "Hoa", "Trung binh", "Hoc luc", "Xep hang");
	for(i=0; i<n; i++)
	printf("%-8s %-25s %-2d/%-2d/%-6d %-10s %-6.2f %-6.2f %-6.2f %-15.2f %-10s %-2d\n", a[i].MSV, a[i].Name, a[i].Birthday.d, a[i].Birthday.m, a[i].Birthday.y, a[i].Sex, a[i].Marks.toan, a[i].Marks.ly, a[i].Marks.hoa, a[i].Marks.TB, a[i].Hocluc, a[i].Rank );
	
}
void ReName(SV *a, int n, char *x, char *y){
	int i;
	for(i=0; i<n; i++){
		if(strcmp(a[i].MSV, x) == 0 ){
			strcpy(a[i].Name, y);
			break;
		}
	}
}
void Search(SV *a, int n, char *x){
	int i;
	printf("Danh sach sinh vien co ten: %s.\n", x);
	for(i=0; i<n; i++)
		if(strcmp(a[i].Name, x) == 0)
			Xuat(a[i]);
}
void GhiFile(SV *b, int n, char *x){
	FILE* fOut = fopen(x, "a");
	int i;
	for(i=0; i<n; i++){
		SV a = b[i];
		fprintf(fOut, "%-8s %-25s %-2d/%-2d/%-6d %-10s %-6.2f %-6.2f %-6.2f %-15.2f %-10s\n", a.MSV, a.Name, a.Birthday.d, a.Birthday.m, a.Birthday.y, a.Sex, a.Marks.toan, a.Marks.ly, a.Marks.hoa, a.Marks.TB, a.Hocluc );

	}
	fclose(fOut);
}

int main(){
	int d = Login();
	if(d == 0)	return 0;
	int n; printf("Nhap so luong sinh vien: "); scanf("%d", &n);
	SV a[n+100];	NhapDSSV(a, n);	XuatDSSV(a, n);
	int k;
	do{
		printf("\n===============MENU=============\n");
		printf("1. Them sinh vien.\n");
		printf("2. Hien thi danh sach.\n");
		printf("3. Sap xep theo ten.\n");
		printf("4. Sap xep theo diem trung binh.\n");
		printf("5. Xep hang.\n");
		printf("6. Doi ten sinh vien theo MSV.\n");
		printf("7. Tim sinh ien theo ten.\n");
		printf("8. Ghi vao file.\n");
		printf("0. Ket thuc.\n");
		printf("Lua chon thao tac: "); scanf("%d", &k);
		switch (k){
			case 1: {
				Add(a, &n);
				break;
				
			}
			case 2: {
				XuatDSSV(a, n);
				break;
			}
			case 3: {
				SwapName(a, n);
				break;
			}
			case 4: {
				SwapMarks(a, n);
				break;
			}
			case 5: {
				Rank(a, n);
				break;
			}
			case 6: {
				printf("Nhap MSV: ");
				char x[5]; scanf("%s", x);
				printf("Nhap ten moi: ");
				char y[100]; fflush(stdin); fgets(y, sizeof(y), stdin); XoaXuongDong(y); ChuanHoa(y);
				ReName(a, n, x, y);
				break;
			}
			case 7: {
				printf("Nhap ten sinh vien: "); char x[100]; fflush(stdin); fgets(x, sizeof(x), stdin); XoaXuongDong(x); ChuanHoa(x);
				Search(a, n, x);
				break;
			}
			case 8:{
			//	printf("Nhap ten file: "); char x[100]; scanf("%s", x);
				GhiFile(a, n, "D:\\C\\quanLiSV\\output.txt");
				break;
			}
			case 0:{
				printf("================================== Cam on da su dung =================================");
				break;
			}
		}
	}while (k != 0);
	return 0;
}







