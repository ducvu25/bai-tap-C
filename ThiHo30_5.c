#include <stdio.h>
#include <string.h>
int KiemTra(char *s){
	int i;
	for(i=0; i<=strlen(s)/2; i++)	// kiem tra 1 nua ben phai roi so sanh ben trai
		if(s[i] != s[strlen(s) - 1 - i]) // neu phan tu doi xung cua phan tu i khac nhau thi tra ve 0
			return 0;
	return 1;	// sau khi duyet het thi co nghia la xau doi xung
}
int main(){
	char s1[1000];
	scanf("%s", s1);
	if(KiemTra(s1) == 1)
		printf("La xau doi xung\n");
	else
		printf("Khong phai xau doi xung\n");
	int i, count = 0;
	for(i=0; i<strlen(s1); i++)
		if(s1[i] == 'X')
			count++;
	printf("So lan xuat hien ky tu X la: %d", count);
}
