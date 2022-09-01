/*
#include <stdio.h>

int main(){
	float a[3];
	printf("Nhap gia tri x, y, z: ");
	scanf("%f%f%f", &a[0], &a[1], &a[2]);
	float sum = a[0] + a[1] + a[2];
	float TB = sum/3;
	printf("Tong 3 so la: %0.2f\n", sum);
	printf("Trung binh cong cua 3 so la: %0.2f", TB);
	int i, j;
		for(i=0; i<2; i++)
			for(j=i+1; j<3; j++)
				if(a[i]*sum > a[j]*sum){
					float t = a[i];
					a[i] = a[j];
					a[j] = t;
				}
	printf("\n%0.2f \t %0.2f \t %0.2f", a[0], a[1], a[2]);
}
*/
#include <stdio.h>

int main(){
	int n;
	do{
		printf("Nhap n: ");
		scanf("%d", &n);
	}while(n < 5 || n > 30);	// neu n nho hon 5 hoac lon hon 30 se phai nhap lai
	float a[n];
	int i;
	for(i=1; i<= n; i++)
		scanf("%f", &a[i]);
	printf("\nMang vua nhap:");
	for(i=1; i <= n; i++)
		printf(" %.2f", a[i]);
	float max = a[1], min = a[1];
	int  x = 1, y = 1;	// x: vi tri gtri max, y la vtri min
	// tim gtri max, min
	for(i=2; i<=n; i++){
		if(max < a[i]){
			max = a[i];
			x = i;
		}
		if(min > a[i]){
			min = a[i];
			y = i;
		}
	}
	// Dao gtri o vi tri max va min
	float t = a[x];
	a[x] = a[y];
	a[y] = t;
	printf("\nMang moi:");
	for(i=1; i <= n; i++)
		printf(" %.2f", a[i]);
	printf("\nCac vi tri cua phan tu bang gtri nho nhat la: ");
	for(i=1; i<=n; i++)
		if(a[i] == min)// neu a[i] bang gtri min vua tim duoc thi in ra vi tri 
			printf("%d ", i);
}

/*
#include <stdio.h>

int main(){
	int s;
	do{
		printf("Nhap quang duong: ");
		scanf("%d", &s);
	}while(s <= 0);
	float time;
	if(s <= 3000)
		time = s*1.5;
	else	if(s <= 5000)
		time = 3000*1.5 + (s - 3000)*2.5;
	else	if(s <= 6000)
		time = 3000*1.5 + 2000*2.5 + (s - 5000)*4.5;
	else	
		time = 3000*1.5 + 2000*2.5 + 1000*4.5 * (s - 6000)*7.5;
	printf("Thoi gian di la: %0.1f (s)", time);
}

#include <stdio.h>

int main(){
	int n;
	do{
		printf("Nhap n: ");
		scanf("%d", &n);
	}while(n < 10 || n > 30); // Neu n nho hon 10 hoac lon hon 30 thi nhap lai n
	
	int a[n], i;
	a[0] = 1;
	a[1] = 1;
	for(i=2; i<n; i++)
		a[i] = a[i-1] + a[i-2]; //  cong thuc tinh a[i]
	printf("\nMang duoc tao:\n");
	for(i=0; i<n; i++)
		printf("%d ", a[i]);
	float sum = 0, sl = 0;
	for(i=0; i<n; i++)
		if(a[i] % 3 == 0){
			sum += a[i];
			sl++;
		}
	printf("\nTrung binh cong cac so chia het cho 3 trong mang la: %0.2f", sum*1.0/sl);
	printf("\nCac cap so le trong day: ");
	for(i=0; i<n-1; i++)
		if(a[i]*a[i+1] % 2 == 1)
			printf("(%d, %d) ", a[i], a[i+1]);
}
*/
