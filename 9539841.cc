#include <iostream>
#include <stdlib.h>

using namespace std;
void dfs(int** g, int a, int n, int t, int** g2){
	for(int i=0; i<n; i++)
		if(g[a][i]==1&&g2[t][i]==0){
			g2[t][i]=1;
			dfs(g, i, n, t, g2);
		}
	return;
}
int main(void) {
	int n;
	cin >> n;
	int** g;
	g = (int**)malloc(sizeof(int*)*n);
	for(int i=0; i<n; i++)
		g[i] = (int*)malloc(sizeof(int)*n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin >> g[i][j];
	int** g2;
	g2 = (int**)malloc(sizeof(int*)*n);
	for(int i=0; i<n; i++)
		g2[i] = (int*)malloc(sizeof(int)*n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			g2[i][j]=0;
	int t=0;
	int tmp=0;
	int tmp2=0;
	while(t<n){
		dfs(g,t,n,t,g2);
		t++;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++)
			cout<<g2[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
