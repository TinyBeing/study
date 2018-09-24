#include <iostream>
#include <cstdio>
using namespace std;
bool r;
int dp[2001][2001];
int main(void){
	int N;
	scanf("%d", &N);
	int* lst = new int[N+1];
	for(int i=1; i<=N; i++)
		scanf("%d", &lst[i]);
	int M;
	int a,b;
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		scanf("%d%d", &a, &b);
		int x,y;
		x = a;
		y = b;
		r = true;
		while(x<=y){
			if(dp[x][y]==1)
				break;
			if(dp[x][y]==-1){
				r=false;
				while(x!=a&&y!=b)
					dp[--x][++y]=-1;
				break;
			}
			if(lst[x]==lst[y]){
				dp[x][y] = 1;
				x++;
				y--;
			}
			else{
				dp[x][y] = -1;
				while(x!=a&&y!=b)
					dp[--x][++y]=-1;
				r = false;
				break;
			}
		}
		if(r)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}
