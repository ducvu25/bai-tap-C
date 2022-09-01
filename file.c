#include <stdio.h>
#include <string.h>

typedef struct{
	char MSV[9];
	char fullName[100];
	int year;
	char SDT[11];
}SV;
void ChuanHoa(char *a){
    int i;
    for(i=0; i<strlen(a); i++){
        if( a[i] >= 'A' && a[i] <= 'Z')
            a[i] += 32;
        if((i == 0 && a[i] >= 'a' && a[i] <= 'z') || (a[i - 1] == 32 && a[i] >= 'a' && a[i] <= 'z' )) 
            a[i] -= 32;
    }
}
SV Nhap(){
	SV a;
	printf("\nNhap MSV: ");	scanf("%s", a.MSV);
	printf("Nhap ho va ten: "); fflush(stdin); fgets(a.fullName, sizeof(a.fullName), stdin);
	if(a.fullName[strlen(a.fullName) - 1] == '\n')
		a.fullName[strlen(a.fullName) - 1] = '\0';
	printf("Nhap nam sinh: "); scanf("%d", &a.year);
	printf("Nhap SDT: "); scanf("%s", a.SDT);
	return a;
}
void Sort(SV *a, int n){
	int i, j;
	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
			if(a[i].year > a[j].year){
				SV t = a[i];
				a[i] = a[j];
				a[j] = t;
			}
}
int main(){
	SV a[100];
	int n = 0, i, k;
	char c;
	do{
		printf("\n=====MENU=====");
		printf("\n1. Nhap sinh vien.");
		printf("\n2. Xuat sinh vien.");
		printf("\n3. Sap xep.");
		printf("\n4. Xuat file DL.DAT.");
		printf("\n0. Thoat.");
		printf("\n\tChuc nang: "); scanf("%d", &k);
		switch(k){
			case 1:{
				printf("Nhap thong tin:\n");
				do{
					a[n] = Nhap();
					n++;
					printf("\nBan co muon nhap tiep(y/n)? ");
					fflush(stdin);
					scanf("%c", &c);
				}while(c != 'n');
				break;
			}
			case 2:{
				printf("\n\nDanh sach: \n");
				printf("%-8s \t%-20s \t%-4s \t%12s\n", "MSV", "Ho va ten", "Nam", "SDT");
				for(i=0; i<n; i++){
					ChuanHoa(a[i].fullName);
					printf("%-8s \t%-20s \t%-4d \t%12s\n", a[i].MSV, a[i].fullName, a[i].year, a[i].SDT);
				}
				break;
			}
			case 3:{
				printf("\n\nDanh sach sau khi sap xep: \n");
				Sort(a, n);
				printf("%-8s \t%-20s \t%-4s \t%12s\n", "MSV", "Ho va ten", "Nam", "SDT");
				for(i=0; i<n; i++){
					printf("%-8s \t%-20s \t%-4d \t%12s\n", a[i].MSV, a[i].fullName, a[i].year, a[i].SDT);
				}
				break;
			}
			case 4:{
				FILE* fp ;
				fp = fopen("DL.DAT", "w");
				fprintf(fp, "\n\t\tDanh sach\n");
				for(i=0; i<n; i++)
					if(a[i].year > 2000)
						fprintf(fp, "%-8s \t%-20s \t%-4d \t%12s\n", a[i].MSV, a[i].fullName, a[i].year, a[i].SDT);
				fclose(fp);	
				printf("\n\tDa xuat vao file.");				
				break;
			}
			case 0:{
				printf("\nKet thuc.");
				break;
			}
		}
	}while(k != 0);
	
	return 0;
}
