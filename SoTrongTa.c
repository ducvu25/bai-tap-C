#include <stdio.h>
#include <string.h>

int main(){  
    char n[200], m[200];
    scanf("%s", n);
    int i, j = 0;
    int d = 0;
    for(i=strlen(n)-1; i>=0; i--){
        if(d > 0 && d % 3 == 0){
           m[j] = ',';
           j++;
        }
        m[j] = n[i];
        j++;
        d++;
    }
    strrev(m);
    printf("%s", m);
    return 0;
}

