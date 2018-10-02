#include <cstdio>
using namespace std;
int n,k;
int dp[10001]={0,};
int main(void){
	scanf("%d%d",&n,&k);
	int* lst = new int[n];
	for(int i=0; i<n; i++){
		scanf("%d",&lst[i]);
	}
	for(int i=0; i<n; i++){
		dp[k-lst[i]]++;
		for(int j=lst[i];j<=k;j++){
			dp[k-j] += dp[k-j+lst[i]];
		} 
	}
	printf("%d", dp[0]);
	return 0;
}
