#include <stdio.h>

int TongCot(int a[][100], int m, int x){
	int sum = 0, i;
	for(i=0; i<m; i++)
		sum += a[i][x];
	return sum;
}

int main(){
	int n, i, j, max;
	int a[100][100];
	scanf("%d", &n);
	scanf("%d", &a[0][0]);
	max = a[0][0];
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if(i == 0 && j == 0)
				continue;
			else{
				scanf("%d", &a[i][j]);
				max = (max > a[i][j]) ? max : a[i][j];
			}
	int min = TongCot(a, n, 0);
	j = 0;
	for(i=1; i<n; i++)
		if(min > TongCot(a, n, i)){
			min = TongCot(a, n, i);
			j = i;
		}
	if(min % 2 == 0){
		int min1 = a[0][0];
		int sum = a[0][0];
		for(i=1; i<n; i++){
			sum += a[i][i];
			min1 = (min1 < a[i][i]) ? min1 : a[i][i];
		}
		sum += max - min1;
		printf("%d", sum);
	}else{
		int min1 = a[0][n-1];
		int sum = a[0][n-1];
		for(i=1; i<n; i++){
			sum += a[i][n - 1 - i];
			min1 = (min1 < a[i][n - 1 - i]) ? min1 : a[i][n - 1 - i];
		}
		sum += max - min1;
		printf("%d", sum);
	}
}
