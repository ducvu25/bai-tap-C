
#include <stdio.h>

int main(){
	int n, i, j;
	printf("Nhap n: "); scanf("%d", &n);
	int *a = (int*)malloc(n*sizeof(int));
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	printf("Dia chi cac pt trong mang: \n");
	for(i=0; i<n; i++)
		printf("a[%d] co dia chi %d\n", i, a + i);
		
	for(i=0; i<n-1; i++)
		for(j=i+1; j<n; j++)
			if(a[i] < a[j]){
				int t = a[i];
				a[i] = a[j];
				a[j] = t;
			}	
	for(i=0; i<n; i++)
		printf("%d ", *(a+i));
}
/*
2:


#include <stdio.h>

int main(){
	int n, i;
	printf("Nhap n: "); scanf("%d", &n);
	int *a = (int*)malloc(n*sizeof(int));
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);
	int max = a[0], x = 0;
	for(i=1; i<n; i++)
		if(max < a[i]){
			max = a[i];
			x = i;
		}
	printf("max = %d o vi tri %d", max, x + 1);
}
