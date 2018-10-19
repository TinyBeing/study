#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
int main(void){
	int n,m;
	scanf("%d%d",&n,&m);
	int** t = new int*[n+1];
	for(int i=1; i<=n; i++){
		t[i] = new int[n+1];
	}
	int a,b;
	for(int i=0; i<m; i++){
		scanf("%d%d",&a,&b);
		t[a][b] = 1;
	}
	int count = 0;
	stack<int> q;
	bool* re = new bool[n+1];
	re = new bool[n+1];
	int tmp;
	int cc;
	for(int i=1; i<=n; i++){
		cc=0;
		q.push(i);
		memset(re,false,n+1);
		while(!q.empty()){
			tmp = q.top(); q.pop();
			if(re[tmp]==false){
			re[tmp]=true;
			cc++;
			for(int k=1;k<=n;k++){
				if(t[tmp][k]==1){
					q.push(k);
				}
			}
			}
		}
		re[i]=false;
		q.push(i);
		while(!q.empty()){
			tmp = q.top(); q.pop();
			if(re[tmp]==false){
			re[tmp]=true;
			cc++;
			for(int k=1;k<=n;k++){
				if(t[k][tmp]==1&&!re[k]){
					q.push(k);
				}
			}
			}
		}
		int j=1;
		if(cc==n+1)
			count++;
	}
	printf("%d",count);
	return 0;
}
