/*
#include <stdio.h>
#include <stdlib.h>
typedef struct Ngay{
	int x;
	int y;
}date;

date* Doc(char *s, int *n){
	FILE* input;
	input = fopen("./Input20.txt", "r");
	fscanf(input, "%d", n);
	int i;
	date* a = (date*)malloc(*n*sizeof(date));
	for(i=0; i<*n; i++){
		fscanf(input, "%d%d", &a[i].x, &a[i].y);
	}
	return a;
}
int KiemTra(date* a, int n){
	int i;
	int sumx = 0, sumy = 0;
	for(i=0; i<n; i++){
		sumx += a[i].x;
		sumy += a[i].y;
		if(sumx < sumy)
			return 0;
	}
	return 1;
}
int SNgayDie(date* a, int n){
	int i, count = 0;
	int max = a[0].y;
	for(i = 1; i<n; i++){
		if(max < a[i].y)
			max = a[i].y;
	}
	for(i = 0; i<n; i++)
		if(a[i].x < 100 && a[i].y == max)
			count++;
	return count;
}
int main(){
	int n, i;
	char s[100];
	fgets(s, sizeof(s), stdin);
	date *a;
	a = Doc(s, &n);
	printf("Thong tin file:\n");
	for(i = 0; i<n; i++)
		printf("%d %d\n", a[i].x, a[i].y);
	if(KiemTra(a, n) == 1)
		printf("Du lieu hop ly!\n");
	else
		printf("Du lieu khong hop ly!\n");
	
	printf("So ngay tu tu vong cao nhat va so nguoi mac moi < 100 la: %d", SNgayDie(a, n));
	
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct GiaoVien{
	char name[50];
	int tuoi;
	char Mon[20];
}GV;
void Xuat(GV x){
	printf("\nThong tin:\n");
	printf("Ho ten: %s", x.name);
	printf("Tuoi: %d\n", x.tuoi);
	printf("Mon day: %s\n", x.Mon);
}
GV* Doc(int *n){
	int i;
	FILE* input;
	input = fopen("inout.txt", "r");
	fscanf(input, "%d", n);
	GV* a;
	a = (GV*)malloc(*n*sizeof(GV));
	char tam[50];
	for(i=0; i<*n; i++){
		fgets(tam, sizeof(tam), input);
		fgets(a[i].name, sizeof(a[i].name), input);
		fscanf(input, "%d%s", &a[i].tuoi, a[i].Mon);
	}
	return a;
}
void ThongKe(GV *a, int n){
	int i, count = 0;
	for(i=0; i<n; i++)
		if(strcmp(a[i].Mon, "Toan") == 0)
			count++;
	printf("\nSo GV mon Toan: %d", count);
	
	count = 0;
	for(i=0; i<n; i++)
		if(strcmp(a[i].Mon, "Van") == 0)
			count++;
	printf("\nSo GV mon Van: %d", count);
	
	count = 0;
	for(i=0; i<n; i++)
		if(strcmp(a[i].Mon, "Anh") == 0)
			count++;
	printf("\nSo GV mon Anh: %d", count);
	
	count = 0;
	for(i=0; i<n; i++)
		if(strcmp(a[i].Mon, "Ly") == 0)
			count++;
	printf("\nSo GV mon Ly: %d\n", count);
}
void Yb(GV *a, int n){
	int i, max = a[0].tuoi;
	for(i=1; i<n; i++)
		if(max < a[i].tuoi)
			max = a[i].tuoi;
	printf("\nThong tin cac giao vien co tuoi cao nhat:\n");
	for(i=0; i<n; i++)
		if(a[i].tuoi == max)
			Xuat(a[i]);
}
void Yc(char *s, GV *a, int n){
	int i, count = 0;
	FILE *out;
	out = fopen("./output.txt", "w");
	for(i=0; i<n; i++)
		if(strcmp(a[i].Mon, s) == 0){
			fprintf(out, "%s %d\n", a[i].name, a[i].tuoi);
			count++;
		}
	fprintf(out, "%d\n", count);
}
int main(){
	int n, i;
	GV *a;
	a = Doc(&n);
	ThongKe(a, n);
	Yb(a, n);
	char s[100];
	fgets(s, sizeof(s), stdin);
	Yc(s, a, n);
}
