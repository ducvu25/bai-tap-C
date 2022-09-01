#include <stdio.h>
#include <string.h>

typedef struct ThongTin{
	char Ten[50];
	char Tg[50];
	char theLoai[20];
	int chieuDai;
	int chieuRong;
	float Gia;
}Tranh;
void XoaEnter(char *a){
	if(a[strlen(a) - 1] == '\n')
		a[strlen(a) - 1] = '\0';
}
void Menu(){
	printf("\n\t\tMENU\n");
	printf("\n1. Nhap thong tin tranh.");
	printf("\n2. Xuat danh sach. ");
	printf("\n3. Sap xep theo ten tang dan A-Z.");
	printf("\n4. Sap xep theo dien tich giam dan.");
	printf("\n5. Thong ke tranh theo tac gia.");
	printf("\n6. Tim va hien thi theo the loai, gia ban thap nhat va nho nhat.");
	printf("\n7. Ghi file.");
	printf("\n8. Doc file. ");
	printf("\n9. Thoat.");
	printf("\n\t Chuc nang: ");
}
Tranh Nhap(){
	Tranh a;
	printf("\nNhap ten tranh: "); fflush(stdin); fgets(a.Ten, sizeof(a.Ten), stdin);	XoaEnter(a.Ten);
	printf("Nhap ten tac gia: "); fflush(stdin); fgets(a.Tg, sizeof(a.Tg), stdin);	XoaEnter(a.Tg);
	printf("Nhap the loai: "); fflush(stdin); fgets(a.theLoai, sizeof(a.theLoai), stdin);XoaEnter(a.theLoai);
	printf("Nhap chieu dai: "); scanf("%d", &a.chieuDai);
	printf("Nhap chieu rong: "); scanf("%d", &a.chieuRong);
	printf("Nhap gia: "); scanf("%f", &a.Gia);
	return a;
}
void Xuat(Tranh a){
	printf("%-20s |%-20s |%-20s |%-10d |%-10d |%-10.2f\n", a.Ten, a.Tg, a.theLoai, a.chieuDai, a.chieuRong, a.Gia);
}
void SortTen(Tranh *a, int n){
	int i, j;
	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
			if(strcmp(a[i].Ten,a[j].Ten) < 0){
				Tranh t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
}
void SortS(Tranh *a, int n){
	int i, j;
	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
			if(a[i].chieuDai*a[i].chieuRong <a[j].chieuDai*a[j].chieuRong){
				Tranh t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
}
void ThongKe(Tranh *a, int n, char *TacGia){
	int i;
	printf("%-20s |%-20s |%-20s |%-10s |%-10s |%-10s\n", "Ten tranh", "Ten tac gia", "The loai", "Chieu dai", "Chieu rong", "Gia");
	for(i=0; i<n; i++);
		if(strcmp(a[i].Tg, TacGia) == 0)
			Xuat(a[i]);
}
void theLoai(Tranh *a, int n, char *TheLoai){
	int i;
	printf("%-20s |%-20s |%-20s |%-10s |%-10s |%-10s\n", "Ten tranh", "Ten tac gia", "The loai", "Chieu dai", "Chieu rong", "Gia");
	for(i=0; i<n; i++);
		if(strcmp(a[i].Tg, TheLoai) == 0)
			Xuat(a[i]);
}
float GiaMin(Tranh *a, int n){
	float min = a[0].Gia;
	int i;
	for(i=1; i<n; i++)
		if(min > a[i].Gia)
			min = a[i].Gia;
	return min;
}
void ThongTinMin(Tranh *a, int n){
	float min = GiaMin(a, n);
	int i;
	printf("%-20s |%-20s |%-20s |%-10s |%-10s |%-10s\n", "Ten tranh", "Ten tac gia", "The loai", "Chieu dai", "Chieu rong", "Gia");
	for(i=0; i<n; i++);
		if(a[i].Gia == min)
			Xuat(a[i]);
}
int main(){
	Tranh a[100];
	int k1, k2, n = 0;
	do{
		Menu();
		scanf("%d", &k1);
		switch(k1){
			case 1:{
				a[n] = Nhap();
				n++;
				break;
			}
			case 2:{
				printf("\n\t\tDanh sach\n");
				printf("%-20s |%-20s |%-20s |%-10s |%-10s |%-10s\n", "Ten tranh", "Ten tac gia", "The loai", "Chieu dai", "Chieu rong", "Gia");
				int i;
				for(i=0; i<n; i++)
					Xuat(a[i]);
				break;
			}
			case 3:{
				SortTen(a, n);
				printf("\n\tDa sap xep theo ten. Chi tiet dung chuc nang 2!\n");
				break;
			}
			case 4:{
				SortS(a, n);
				printf("\n\tDa sap xep theo dien tich. Chi tiet dung chuc nang 2!\n");
				break;
			}
			case 5:{
				char TacGia[100];
				printf("Nhap ten tac gia: "); fflush(stdin); fgets(TacGia, sizeof(TacGia), stdin); XoaEnter(TacGia);
				ThongKe(a, n, TacGia);
				break;
			}
			case 6:{
				char Loai[100];
				printf("Nhap the loai: "); fflush(stdin); fgets(Loai, sizeof(Loai), stdin); XoaEnter(Loai);
				theLoai(a, n, Loai);
				printf("\nGia Thap\n");
				ThongTinMin(a, n);
				break;
			}
			case 7:{
				char s[100];
				int i;
				printf("Nhap ten file: "); scanf("%s", s);
				FILE* fp ;
				fp = fopen(s, "w");
				fprintf(fp, "\n\t\tDanh sach\n");
				fprintf(fp, "%-20s |%-20s |%-20s |%-10s |%-10s |%-10s\n", "Ten tranh", "Ten tac gia", "The loai", "Chieu dai", "Chieu rong", "Gia");
				for(i=0; i<n; i++)
					fprintf(fp, "%-20s |%-20s |%-20s |%-10d |%-10d |%-10d\n", a[i].Ten, a[i].Tg, a[i].theLoai, a[i].chieuDai, a[i].chieuRong, a[i].Gia);
				fclose(fp);
				break;
			}
			case 8:{
				char s[100];
				int i;
				printf("Nhap ten file: "); scanf("%s", s);
				FILE *fb;
				if((fb = fopen(s, "r")) == NULL){
					printf("Khong co file");
				}else{
					fscanf(fb, "%d", &n);
					for(i=0; i<n; i++){
						fgets(a[i].Ten, 50, fb); XoaEnter(a[i].Ten);
						fgets(a[i].Tg, 50, fb); XoaEnter(a[i].Tg);
						fgets(a[i].theLoai, 50, fb); XoaEnter(a[i].theLoai);
						fscanf(fb, "%d", &a[i].chieuDai);
						fscanf(fb, "%d", &a[i].chieuRong);
						fscanf(fb, "%f", &a[i].Gia);
					}
				}
				
				break;
			}
		}
	}while(k1 != 8);
}
