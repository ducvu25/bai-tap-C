#include <stdio.h>

int main(){
	int kieu;
	scanf("%d", &kieu);
	switch(kieu){
		case 1:{
			int n;
			scanf("%d", &n);
			if(n <= 0)
				printf("Invalid request");
			else{
				int i, j;
				for(i=0; i<n; i++){
					for(j=0; j<n-i; j++)
						printf("*");
					printf("\n");
				}
			}
			break;
		}
		case 2:{
			int n;
			scanf("%d", &n);
			if(n <= 0)
				printf("Invalid request");
			else{
				int i, j;
				for(i=0; i<n; i++){
					for(j=0; j<=n+i; j++)
						if(j>= n - i)
							printf("*");
						else
							printf(" ");
					printf("\n");
				}
			}
			break;
		}
		case 3:{
			int size1, size2;
			scanf ("%d", &size1);
			scanf ("%d", &size2);
			if(size1 <= 0 || size2 <= 0)
				printf("Invalid request");
			else{
				int b,i, j, d = size1;
    			b = 2*size1 + size2 - 2;
    			for(i=0; i < size1; i++){
    				d--;
    				for(j=0; j<b; j++)
    					if(i == 0 || i == size1 - 1)
    						if(j >= d && j < b - d)
    							printf("*");
    						else
    							printf(" ");
    					else
    						if(j == d || j == b - d - 1)
    							printf("*");
    						else
    							printf(" ");
    				printf("\n");
    			}
			}
			break;
		}
	}
}
