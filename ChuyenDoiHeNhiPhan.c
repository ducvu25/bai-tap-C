#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct Node{
	int v, l;
}Node;
Node T[1000];
int n, N, test, i;
char s[1000];
void Input() {
	freopen("C:\\Users\\DUC VU\\Downloads\\bin\\input.txt","r",stdin);
	freopen("C:\\Users\\DUC VU\\Downloads\\bin\\output.txt","w",stdout);
	scanf("%d", &n);
	scanf("%s", s);
}
Node Gan(int x, int y){
	Node a;
	a.v = x;
	a.l = y;
	return a;
}

int pow_mod(int n, int k, int m) {
	if(k == 0)
		return (1 % m);
	if(k == 1)
		return (n % m);
	int b = pow_mod(n, k / 2, m);
	if(k % 2 == 0)
		return (b * b) % m;
	return (b * b * n) % m;
}

Node Tong(Node a, Node b){
	return Gan((a.v * pow_mod(2, b.l, 3) + b.v) % 3, a.l + b.l);
}
void update(int id, int l, int r, int x, int v) {
	if(x < l || r < x)
		return;
	if(l == r) {
		T[id] = Gan(v, 1);
		return;
	}
	int mid = (l + r) / 2;
	update(id * 2, l, mid, x, v);
	update(id * 2 + 1, mid + 1, r, x, v);
	T[id] = Tong(T[id * 2], T[id * 2 + 1]);
}
Node get(int id, int l, int r, int L, int R) {
	if(r < L || R < l)
		return Gan(0, 0);
	if(L <= l && r <= R)
		return T[id];
	int mid = (l + r) / 2;
	return Tong(get(id * 2, l, mid, L, R), get(id * 2 + 1, mid + 1, r, L, R));
}

int ST_RunQuery(int t, int x, int y) {
	if(t == 0) {
		Node ret = get(1, 0, n - 1, x, y);
		return ret.v;
	} else if(t == 1) {
		if(s[x] == '1')
			return 0;
		s[x] = '1';
		update(1, 0, n - 1, x, 1);
		return 1;
	}
	return -1;
}
void ST_Process() {
	int i;
	for(i = 0; i < n; i++)
		if(s[i] == '1')
			update(1, 0, n - 1, i, 1);
		else
			update(1, 0, n - 1, i, 0);
	scanf("%d", &N);
	while(N --> 0) {
		int t, x, y = -1;
		scanf("%d", &t);
		if(t == 0)
			scanf("%d %d", &x, &y);
		else if(t == 1)
			scanf("%d", &x);
		int ret = ST_RunQuery(t, x, y);
		if(t == 0)
			printf("%d\n", ret);
	}
}
int main(){
	Input();
	ST_Process();
}
/*
5
10010
6
0 2 4
0 2 3
1 1
0 0 4
1 1 
0 0 3
*/
