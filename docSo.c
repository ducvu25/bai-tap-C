/*
#include <stdio.h>
#include <string.h>

int main(){
	char a[100];
	do{
		printf("Nhap so a trong khoang 10 den 100: ");
		scanf("%s", a);
	}while( a[0] == '-' || strlen(a) > 2 || strlen(a) == 1);
	
	switch (a[strlen(a) - 2] - 48){
		case 1:{
				printf("Muoi");
			if(a[strlen(a) -1] == 48){
				return 0;
			}
			break;
		}
		case 3:{
			printf("Ba muoi");
			if(a[strlen(a) -1] == 48)
				return 0;
			break;
			}
		case 4:{
			printf("Bon muoi");
			if(a[strlen(a) -1] == 48)
				return 0;
			break;
			}
		case 5:{
			printf("Nam muoi");
			if(a[strlen(a) -1] == 48)
				return 0;
			break;
		}
		case 6:{
			printf("Sau muoi");
			if(a[strlen(a) -1] == 48)
				return 0;
			break;
		}
		case 7:{
			printf("Bay muoi");
			if(a[strlen(a) -1] == 48)
				return 0;
			break;
		}
		case 8:{
			printf("Tam muoi");
			if(a[strlen(a) -1] == 48)
				return 0;
			break;
		}
		case 9:{
			printf("Chin muoi");
			if(a[strlen(a) -1] == 48)
				return 0;
			break;
		}
		}
	switch (a[strlen(a) - 1] - 48){
		case 0 :{
			printf(" khong");
			break;
		}
		case 1 :{
			printf(" mot");
			break;
		}
		case 2 :{
			printf(" hai");
			break;
		}
		case 3 :{
			printf(" ba");
			break;
		}
		case 4 :{
			printf(" bon");
			break;
		}
		case 5 :{
			printf(" nam");
			break;
		}case 6 :{
			printf(" sau");
			break;
		}
		case 7 :{
			printf(" bay");
			break;
		}
		case 8 :{
			printf(" tam");
			break;
		}
		case 9 :{
			printf(" chin");
			break;
		}
	}
}
*/
#include <stdio.h>

int main(){
	int n, i;
	do{
		printf("Nhap n trong doan [4, 40]: "); 
		scanf("%d", &n);
	}while(n < 4 || n > 40);
	float a[n];
	for(i=0; i<n; i++)
		scanf("%f", &a[i]);
	printf("\nMang so thuc da nhap:\n");
	for(i=0; i<n; i++)
		printf("%0.2f ", a[i]);
	float sumAm = 0, soLuong = 0;
	for(i=0; i<n; i+=2)
		if(a[i] < 0){
			sumAm += a[i];
			soLuong+= 1;
		}
	printf("\nTong cac phan tu am co chi so chan trong mang: %0.2f", sumAm);
	printf("\nTrung binh cong cua cac phan tu am co chi so chan trong mang: %0.2f", sumAm/soLuong);
}
