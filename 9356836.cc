#include <iostream>
#include <stdlib.h>

using namespace std;

void dfs(int** g, int v, int a, int* visited){
	visited[v-1] = 1;
	cout<<v<<" ";
	int i;
	for(i=0; i<a; i++){
		if(g[v-1][i]==1&&visited[i]==0)
			dfs(g,i+1,a,visited);
	}
	return;
}
void enq(int* q, int n){
	int i=0;
	while(q[i]!=-1){
		i++;
	}
	q[i]=n;
}
int deq(int* q){
	int i=0;
	int r = q[0];
	while(q[i]!=-1){
		q[i]=q[i+1];
		i++;
	}
	return r;

}

void bfs(int** g, int v, int a, int* visited)
{
	int* q;
	int s;
	q = (int*)malloc(sizeof(int)*a);
	for(int i=0; i<a; i++)q[i]=-1;
	visited[v-1]=1;
	enq(q, v);
	while(q[0]!=-1){
		s = deq(q);
		cout<<s<<" ";
		for(int i=0; i<a; i++){
			if(g[s-1][i]==1&&visited[i]==0){
				enq(q,i+1);
				visited[i]=1;
			}
		}	
	}
	
}
int main(void){

	int** matrix;
	int n;
	int m;
	int v;
	int n2;
	int a,b;

	cin>>n>>m>>v;
	int* visited;
	visited = (int*)malloc(sizeof(int)*n);
	for(int i=0; i<n; i++)
	       visited[i] = 0;
	matrix = (int**)malloc(sizeof(int*)*n);
	for(int i=0; i<n; i++)
		matrix[i] = (int*)malloc(sizeof(int)*n);
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			matrix[i][j]=0;

	for(int i=0; i<m; i++)
	{
		cin>>a>>b;
		a--;
		b--;
		matrix[a][b]=1;
		matrix[b][a]=1;
		
	}
	dfs(matrix, v, n, visited);
	
	for(int i=0; i<n; i++)
	       visited[i] = 0;
	cout<<endl;
	bfs(matrix, v, n, visited);
	return 0;
}
