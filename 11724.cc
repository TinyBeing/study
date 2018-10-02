#include <iostream>
#include <vector>
using namespace std;
void search(vector<int> g[1001], int p){
	int tmp;
	while(!g[p].empty()){
	tmp = g[p].back();
	g[p].pop_back();
	search(g, tmp);
	}
}
int main(void){
	int N, M;
	cin >> N >> M;
	int u, v;
	vector<int> g[1001];
	int s[1001];
	for(int i=0; i<M; i++){
		cin >> u >> v;
		s[u] = 1;
		s[v] = 1;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int count = 0;
	for(int i=1; i<N+1; i++)
		if(s[i]!=1)
			count++;
	for(int i=1; i<N+1; i++)
		if(!g[i].empty()){
			search(g, i);
			count++;
		}
	cout << count;
	return 0;
}
