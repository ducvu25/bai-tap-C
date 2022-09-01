#include <stdio.h>

void sort(int a[], int n){
    int i, j;
    for(i=0; i<n-1; i++)
        for(j=i+1; j<n; j++)
            if(a[i] < a[j]){
                int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
}
int main(){
    int n, i;
    scanf("%d", &n);
    int a[100];
    for(i=0; i<n; i++)
        scanf("%d", &a[i]);
    sort(a, n);
    for(i=0; i<n; i++)
        printf("%d ", a[i]);
}
