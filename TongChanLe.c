#include <stdio.h>

long Tong(long n){
	if(n == 1 || n == 2)	return n;
	return n + Tong(n - 2);
}

int main(){
	long n;
	printf("Nhap n: ");
	scanf("%ld", &n);
	printf("Tong = %ld", Tong(n));
}
