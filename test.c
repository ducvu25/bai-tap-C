#include <stdio.h>
#include <string.h>
#include <math.h>

int UCLN(int a, int b){
	if(a == 0) return b;
	if(b == 0) return a;
	if(a > b) return UCLN(a%b, b);
	if(b > a) return UCLN(a, b%a);
	if(a == b) return a;
}
int main(){
	printf("%d", UCLN(100, 20));
}
