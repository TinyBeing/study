#include <cstdio>
#include <algorithm>
int M, N;
int ab(int a) {
	if (a<0)
		return -a;
	else return a;
}
bool isin(int* bt, int a) {
	if(a==0)
		for (int i = 0; i<M; i++)
			if (bt[i] == a)
				return false;
	while (a) {
		for (int i = 0; i<M; i++)
			if (bt[i] == a % 10)
				return false;
		a /= 10;
	}
	return true;
}
int length(int a) {
	int r = 0;
	while (a) {
		a /= 10;
		r++;
	}
	return r;
}
int main() {
	scanf("%d%d", &N, &M);
	int* bt = new int[M];
	
	for (int i = 0; i<M; i++)
		scanf("%d", &bt[i]);
	
	if(M==10){
		printf("%d", ab(100-N));
		return 0;
	}
	int loc = N;
	if (isin(bt, loc)) {
		printf("%d", std::min(ab(N-100),length(loc)));
		return 0;
	}
	loc = -1;
	int up = N + 1;
	int down = N - 1;
	while (loc<0) {
		if (isin(bt, up))
			loc = up;
		if (down>=0&&isin(bt, down))
			loc = down;
		up++; down--;
	}
	int t = ab(N - loc) + length(loc);
	printf("%u", std::min(ab(t), ab(N - 100)));
	return 0;
}


