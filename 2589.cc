#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
int x,y;
int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int dp[51][51];
bool inside(int a, int b){
	return a>=0&&b>=0&&a<x&&b<y;
}
int main(void){
	cin >> x >> y;
	int r=0;
	queue<int> qx;
	queue<int> qy;
	int tmp,tmp2;
	char** c = new char*[x+1];
	for(int i=0; i<x; i++)
		c[i] = new char[y+1];
	for(int i=0; i<x; i++)
		cin >> c[i];
	for(int i=0; i<x; i++)
		for(int j=0; j<y; j++)
			dp[i][j]=0;
	int tx,ty;
	for(int i=0; i<x; i++)
		for(int j=0; j<y; j++)
			if(c[i][j]=='L'){
				qx.push(i);
				qy.push(j);
				while(!qx.empty()){
					tmp = qx.front();
					tmp2 = qy.front();
					qx.pop(); qy.pop();
					for(int k=0; k<4; k++){
						tx = tmp+dir[k][0];
						ty = tmp2+dir[k][1];
						if(inside(tx,ty)&&c[tx][ty]=='L'&&dp[tx][ty]==0){
							dp[tx][ty]=dp[tmp][tmp2]+1;
							qx.push(tx);
							qy.push(ty);
						}
					}
					r=max(r,dp[tmp][tmp2]);
				}
				for(int k=0; k<x; k++)
					for(int t=0; t<y; t++)
						dp[k][t]=0;
			}
	cout << r;
	return 0;
}
