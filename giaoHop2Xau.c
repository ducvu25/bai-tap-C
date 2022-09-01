#include <stdio.h>
#include <string.h>

void TachTu(char mang[][100], char* s, int *n){
    int i, d = 0, j = 0;
    s[strlen(s) - 1] = 32;
    for(i=0; i<strlen(s); i++)
        if(s[i] == 32){
            strncpy(mang[j++], s + d, i - d);
            d = i + 1;
        }
    *n = j;
}
void InThuong(char *s){
    int i;
    for(i=0; i<strlen(s); i++)
        if(s[i] >= 'A' && s[i] <= 'Z')  
            s[i] += 32;
}
int main()
{
    char s1[1000];
    char s2[1000];
    int i, j, n1, n2, u, v;
    fgets(s1, sizeof(s1), stdin);
    fgets(s2, sizeof(s2), stdin);
    InThuong(s1);
    InThuong(s2);
    
    char mangTu1[100][100];
    char mangTu2[100][100];
    char mangTu3[200][100];
    TachTu(mangTu1, s1, &n1);
    TachTu(mangTu2, s2, &n2);
    
    for(i=0; i<n1 + n2; i++)
        if(i < n1)
            strcpy(mangTu3[i], mangTu1[i]);
        else
            strcpy(mangTu3[i], mangTu2[i - n1]);
    for(i=0; i<n1 + n2; i++)
        for(j=i+1; j<n1 + n2; j++)
            if(strcmp(mangTu3[i], mangTu3[j]) > 0){
                char tem[100];
                strcpy(tem, mangTu3[i]);
                strcpy(mangTu3[i], mangTu3[j]);
                strcpy(mangTu3[j], tem);
            }
    strcpy(mangTu3[n1 + n2], mangTu3[0]);
    for(i=0; i<n1 + n2; i++)
        if(strcmp(mangTu3[i], mangTu3[i+1]) != 0)
            printf("%s ", mangTu3[i]);
    printf("\n");
    for(i=0; i<n1 + n2; i++)
        if(strcmp(mangTu3[i], mangTu3[i+1]) != 0){
            int d = 0;
            for(u=0; u<n1; u++)
                if(strcmp(mangTu3[i], mangTu1[u]) == 0){
                    d++;
                    break;
                }
            for(v=0; v<n2; v++)
                if(strcmp(mangTu3[i], mangTu2[v]) == 0){
                    d++;
                    break;
                }
            if(d == 1)
                printf("%s ", mangTu3[i]);
        }
    return 0;
}
