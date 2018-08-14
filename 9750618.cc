#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int lst3[26];
int ans;
inline void mfind(char** bo, int* lst, int count, int x, int y, int l1, int l2){
	lst[bo[y][x]-65] = 1;

	if(l1-1>x && lst[bo[y][x+1]-65]!=1){
		ans = max(ans, count+1);
		mfind(bo, lst, count+1, x+1, y, l1, l2);
	}
	if(l2-1>y && lst[bo[y+1][x]-65]!=1){
		ans = max(ans, count+1);
		mfind(bo, lst, count+1, x, y+1, l1, l2);

	}
	if(x>0 && lst[bo[y][x-1]-65]!=1){
		ans = max(ans, count+1);
		mfind(bo, lst, count+1, x-1, y, l1, l2);

	}
	if(y>0 && lst[bo[y-1][x]-65]!=1){
	        ans = max(ans, count+1);
		mfind(bo, lst, count+1, x, y-1, l1, l2);
	}
	lst[bo[y][x]-65] = 0;
	return;
}
int main(void) {
	int lst[26];
	int R;
	int C;
	ans = 1;
	cin >> R >> C;
	char** b;
	b = (char**)malloc(sizeof(char*)*R);
	for(int i=0; i<R; i++){
		b[i] = (char*)malloc(sizeof(char)*C+1);
		cin >> b[i];
	}
	for(int i=0; i<26; i++)
		lst[i]=0;
	
	mfind(b, lst, 1, 0, 0, C, R);
	
	cout << ans;
	return 0;

}
