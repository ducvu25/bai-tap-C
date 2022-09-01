/* Tao struct da thuc P(x) va Q(x) :
 + Viet ham nhap he so tuong ung voi so mu
 + Tinh P(x)  voi x0 bat ki
 + Tinh P'(x)
 + Tinh da thuc P(x) + Q(x) tra ve da thuc
 + Tinh hieu P(x) - Q(x)
 + Tinh tich P(x) * Q(x)
 + Tinh thuong P(x) / Q(x) va thuong con lai
 + Viet menu
 */
 
#include <stdio.h>
#include <math.h>

 typedef struct DonThuc{
 	float CoSo;
 	int SoMu;
 }DT;

 DT Nhap(){
 	DT a;
 	printf("Nhap so mu: ");	scanf("%d", &a.SoMu);
 	printf("Nhap co so cua x^%d: ", a.SoMu);	scanf("%f", &a.CoSo);
 }
 
 void NhapP(DT *a, int n){
 	printf("\nNhap x^%d: ")
 }
