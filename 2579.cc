#include <iostream>
#include <cstdio>
#define MAX(a, b) ((a)>(b)?(a):(b))
using namespace std;
int N;
int** dp;
int main(void){
	cin >> N;
	int* st = new int[N];
	dp = new int*[N];
	for(int i=0; i<N; i++){
		cin >> st[i];
		dp[i] = new int[2];
		dp[i][0] = 0;
		dp[i][1] = 1;
	}
	if(N==1){
		cout << st[0] << endl;
		return 0;
	}
	dp[0][0] = st[0];
	dp[1][0] = st[1];
	dp[1][1] = st[0]+st[1];
	for(int i=2; i<N; i++){
		dp[i][0] = MAX(dp[i-2][1],dp[i-2][0])+st[i];
		dp[i][1] = dp[i-1][0]+st[i];
	}
	cout << MAX(dp[N-1][0],dp[N-1][1]);
	delete(dp);
	delete(st);
	return 0;
}
