/*#include <stdio.h>

void Nhap(float a[][100], int m, int n){
	printf("\nNhap ma tran:\n");
	int i, j;
	for(i=0; i<m; i++)
	 for(j=0; j<n; j++)
	 	scanf("%f", &a[i][j]);
}

int Boolean(float a[][100], int m, int n, float b[][100], int x, int y){ // Neu la ma tran chuyen vi thi tra ve 1, nguoc lai tra ve 0.
	if(m != y || n != x)	return 0;
	int i, j;
	for(i=0; i<m; i++)
	 for(j=0; j<n; j++)
	  if(a[i][j] != b[j][i]) 	return 0;
	  
	return 1;
}

int main(){
	float a[100][100], b[100][100];
	int m, n, x, y;
	printf("Nhap kich co ma tran: ");	scanf("%d%d", &m, &n);
	Nhap(a, m, n);
	printf("Nhap kich co ma tran: ");	scanf("%d%d", &x, &y);
	Nhap(b, x, y);
	if(Boolean(a, m, n, b, x, y) == 1 ) 	printf("B la ma tran chuyen vi cua A.");
	else									printf("B khong la ma tran chuyen vi cua A.");
}
*/

/* Tao ma tran xoan oc

#include <stdio.h>


/* 				y1

	x1 a00	a01	a02
	   a10	a11	a12
	   a20	a21	a22	x2
	   y2

void Khoitao(int a[][100], int m, int n){
	int x1 = 0, x2, y1 = 0, y2;
	int k = 0;
	int x = 0, y =0;

		for(x1 = x; x1<n-x; x1++)
			if(x1 == n - 1 - x){
			for(y1 = y; y1<m-y; y1++)
				if(y1 == m - 1 - y){
				for(x2=x1; x2 >=x; x2--)
						if(x2 == x){
						for(y2=y1; y2>=y + 1; y2--)
								if(y2 == y + 1){
									a[y2][x2] = k;
									k++;
									x++;
									y++;
									x1 = x - 1;
									y1 = y;
									break;
								}else{
									a[y2][x2] = k;
									k++;
								}
						break;
						}else{
							a[y1][x2] = k;
							k++;
						}
				break;	
				}else{
					a[y1][x1] = k;
					k++;
				}
		}else{
			a[y1][x1] = k;
			k++;
		}	
	if(m%2 ==1 && n%2 == 1)
		a[m/2][n/2] = m*n - 1;
 }

void Xuat(int a[][100], int m, int n){
	int i, j;
	for(i=0; i<m; i++){
		for(j=0; j<n; j++)
			printf("\t%d", a[i][j]);
		printf("\n");
	}
}

int main(){
	int m, n;	printf("Nhap kich co m x n: ");	scanf("%d%d", &m, &n);
	int a[100][100]; printf("Nhap mang a: \n");	Khoitao(a, m, n);
	Xuat(a, m, n);

}

*/

#include  <stdio.h>
#include <math.h>
int main(){
	int n;
	do{
		printf("\nNhap so n (le): ");
		 scanf("%d", &n);
	}while(n %2 == 0);
	
	int i, m =1;
	float sum =2 ;
	for(i=4; i<= n+1; i+= 2){
		m *= (i-1);
		sum += (float) i/m;
	}
	printf("%0.2f", sum);
}

int main(){
	int n;
	printf("\nNhap n: ");
	scanf("%d", &n);
	float s = 0;
	long tu = 1, mau=1;
	int i;
	for(i=1; i<=n; i++){
		tu *= i;
		if(i > 1) 
			mau = pow(2*(i-1), 5); 
		s += (float) tu / mau;
	}
	printf("S = %0.61f", sqrt(s));
}
