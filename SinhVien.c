#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct NgaySinh{
	int d;
	int m;
	int y;
}Date;
typedef struct SinhVien{
	char name[30];
	Date date;
	char xepLoai[20];
}SV;
void Ten(SV a, char *c){
	int i;
	for(i=strlen(a.name)-1; i>=0; i--)
		if(a.name[i] == 32){
			strcpy(c, a.name + i + 1);
			return;
		}
}
void XoaXuongDong(char *a){
	if(a[strlen(a)-1] == '\n')
		a[strlen(a)-1] = '\0';
}
SV Nhap(){
	SV a;
	char c;
	printf("\nNhap ten: "); fgets(a.name, sizeof(a.name), stdin);	XoaXuongDong(a.name);
	printf("Nhap ngay thang nam (day/moth/year): "); scanf("%d%c%d%c%d", &a.date.d, &c, &a.date.m, &c, &a.date.y);
	fflush(stdin);;
	printf("Nhap hoc luc: "); fgets(a.xepLoai, sizeof(a.xepLoai), stdin);	XoaXuongDong(a.xepLoai);
	return a;
}
void Xuat(SV a){
	printf("%-20s %2d/%2d/%-6d %-10s\n", a.name, a.date.d, a.date.m, a.date.y, a.xepLoai);
}
void Sort(SV *a, int n){
	int i, j;
	char s1[20];
	for(i=0; i<n-1; i++){
		for(j=i+1; j<n; j++){
			char s1[20];	Ten(a[i], s1);
			char s2[20];	Ten(a[j], s2);
			if(strcmp(s1, s2) > 0){
				SV t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
		}
	}
	printf("\n\t\tDANH SACH SINH VIEN\n");
	printf("%-20s %-10s %-10s\n", "Ho ten", "Ngay sinh", "Hoc luc");
	for(i=0; i<n; i++)
		Xuat(a[i]);
}
void Nhom(SV *a, int n){
	int i;
	printf("\n\t\tDANH SACH SINH VIEN GIOI\n");
	printf("%-20s %-10s %-10s\n", "Ho ten", "Ngay sinh", "Hoc luc");
	for(i=0; i<n; i++)
		if(strcmp(a[i].xepLoai, "Gioi") == 0)
			Xuat(a[i]);
}
int main(){
	int n, i;
	printf("Nhap so luong: "); scanf("%d", &n);	fflush(stdin);
	SV a[n];
	for(i=0; i<n; i++)
		a[i] = Nhap();
	Sort(a, n);
	Nhom(a, n);
}
