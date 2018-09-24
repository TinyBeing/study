#include <iostream>
using namespace std;
int n;
int c[10000] = {0,};
void search(int** p, int x, int y, int N, int M){
	c[n]++;
	if(x>0&&p[x-1][y]!=1){
		p[x-1][y] = 1;
		search(p, x-1, y, N, M);
	}
	if(y>0&&p[x][y-1]!=1){
		p[x][y-1] = 1;
		search(p, x, y-1, N, M);
	}
	if(x<N-1&&p[x+1][y]!=1){
		p[x+1][y] = 1;
		search(p, x+1, y, N, M);
	}
	if(y<M-1&&p[x][y+1]!=1){
		p[x][y+1] = 1;
		search(p, x, y+1, N, M);
	}
	return;
		
}

int main(void){
	int N,M;
	n=0;
	cin >> N >> M;
	int** p = new int*[N];
	for(int i=0; i<N; i++){
		p[i] = new int[M];
		for(int j=0; j<M; j++)
			p[i][j] = 0;
	}
	int C;
	cin >> C;
	int x1,y1,x2,y2;
	for(int i=0; i<C; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		for(int j=y1; j<y2; j++)
			for(int k=x1; k<x2; k++)
				p[j][k] = 1;
	}
	for(int i=N-1; i>=0; i--)
		for(int j=0; j<M; j++)
			if(p[i][j]!=1){
				p[i][j] = 1;
				search(p, i, j, N, M);
				n++;
			}
	cout << n << endl;
	for(int j=0; j<10000; j++)
		for(int i=0; i<n; i++)
			if(c[i]==j)
				cout << j << " ";
	return 0;
}
