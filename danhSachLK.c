#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char MHP[10];
	char Name[100];
	int Tin;
}MonHoc;
MonHoc Nhap(){
	MonHoc a;
	printf("Nhap MHP: "); scanf("%s", a.MHP);
	printf("Nhap ten: "); fflush(stdin); fgets(a.Name, sizeof(a.Name), stdin);
	if(a.Name[strlen(a.Name) - 1] == '\n')
		a.Name[strlen(a.Name) - 1] = '\0';
	printf("Nhap so tin: "); scanf("%d", &a.Tin);
	return a;
}
void XuatMon(MonHoc a){
	printf("%-10s \t%-20s \t%-5d\n", a.MHP, a.Name, a.Tin);
}
typedef struct{
	MonHoc data;
	Node *next;
}Node;
typedef struct Node* node;
typedef struct{
	node pHead;
	node pTail;
}List;
void KhoiTao(List *L){
	L->pHead = NULL;
	L->pTail = NULL;
}
int KTMa(List l, MonHoc x){
	node p = l.pHead;
	while(p != NULL){
		if(strcmp(p.data.MHP, x.MHP) == 0)
			return 0;
		p = p->next;
	}
	return 1;
}
node TaoNode(MonHoc x){
	node p = new Node;
	p->data = x;
	p->next = NULL;
	return p;
}
void Them(List &l, node p){
	if (l.pHead == NULL){
		l.pHead = p;
		l.pTail = p;
	}else{
		l.pTail->next = p;
		l.pTail = p;
		p->next = NULL;
	}
}
void XuatList(List l){
	node p = l.pHead;
	while(p != NULL){
		XuatMon(p->data);
		p = p->next;
	}
}

int main(){
	List list;
	KhoiTao(&list);
	char c;
	do{
		MonHoc a = Nhap();
		if(KTMa(list, a) == 1){
					node p = TaoNode(a);
					Them(list, p);
				}else
					printf("\n\tKiem tra lai MHP.");
		printf("\nBan muon nhap tiep khong(y/n)?");
		fflush(stdin);
		scanf("%c", &c);
	}while(c != 'n');
	printf("Danh sach:\n ");
	XuatList(list);
	printf("Bo sung: ");
	MonHoc a = Nhap();
	if(KTMa(list, a) == 1){
		node p = TaoNode(a);
		Them(list, p);
	}else
		printf("\n\tKiem tra lai MHP.");
}
