#include <cstdio>
#include <queue>
#include <functional>
using namespace std;
int N;
int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
bool inside(int x, int y){
	return x>=0&&y>=0&&x<N&&y<N;
}
struct point{
	int val;
	int x;
	int y;
};
bool operator<(point a, point b){
	return a.val > b.val;
}
int main(void){
	int num=1;
	scanf("%d",&N);
	while(N){
		int** dp = new int*[N];
		int** cave = new int*[N];
		for(int i=0; i<N; i++){
			dp[i] = new int[N];
			cave[i] = new int[N];
			for(int j=0; j<N; j++){
				scanf("%d",&cave[i][j]);
				dp[i][j] = 99999999;
			}
		}
		priority_queue< point > pq;
		point p;
		p.x = 0;
		p.y = 0;
		p.val = cave[0][0];
		pq.push(p);
		int x,y; dp[0][0] = cave[0][0];
		while(!pq.empty()){
			x = pq.top().x; y = pq.top().y;
			pq.pop();
			for(int i=0; i<4; i++){
				int xd,yd;
				xd = x+dir[i][0]; yd = y+dir[i][1];
				if(inside(xd,yd)&&(dp[xd][yd]>dp[x][y]+cave[xd][yd])){
					dp[xd][yd]=dp[x][y]+cave[xd][yd];
					p.x=xd; p.y=yd; p.val=cave[xd][yd];
					pq.push(p);
				}
			}
		}
		
		printf("Problem %d: %d\n",num++,dp[N-1][N-1]);
		scanf("%d",&N);
	}
	return 0;
}
