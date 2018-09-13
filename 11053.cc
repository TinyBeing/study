#include <iostream>
#include <cstdio>
using namespace std;
char* dp;
int main(void){
	int m,n;
	cin >> m >> n;
	dp = new char[10001];
	for(int i=0; i<=n; i++)
		dp[i] = 0;
	dp[0] = 1;
	dp[1] = 1;
	int sum=0;
	for(int i=2; i*2<=n; i++){
		for(int j=2; j*i<=n; j++)
			dp[j*i]=1;
	}
	int min = 0;
	for(int i=m; i<=n; i++)
		if(dp[i]==0){
			sum+=i;
			if(min==0)
				min = i;
		}
	cout << sum << endl << min;
	return 0;
}


