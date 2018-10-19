#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
int main(void){
	int N;
	cin >> N;
	queue<int> q;
	int** lst = new int*[N];
	int* dp = new int[N];
	for(int i=0; i<N; i++){
		lst[i] = new int[2];
		dp[i] = 0;
		cin >> lst[i][0] >> lst[i][1];
	}
	for(int i=0; i<N; i++){
		q.push(i);
	}
	int tmp;
	while(!q.empty()){
		tmp = q.front(); q.pop();
		if(dp[tmp]==0&&lst[tmp][0]+tmp<=N)
			dp[tmp] = lst[tmp][1];
		for(int i=tmp+lst[tmp][0]; i<N; i++){
			if(dp[i]<dp[tmp]+lst[i][1]&&lst[i][0]+i<=N){
				dp[i] = dp[tmp]+lst[i][1];
				q.push(i);
			}
		}
	}
	int max=0;
	for(int i=0; i<N; i++)
		if(max<dp[i])
			max = dp[i];
	cout << max;
	return 0;
}
