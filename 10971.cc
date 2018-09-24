#include <iostream>
#include <algorithm>
using namespace std;
int mmm;
int* T;
void TSP(int** p, int N, int s, int n, int S, int m){
	if(n<N-1){
	for(int i=0; i<N; i++){
		if(T[i]!=1&&p[s][i]!=0&&i!=S&&(mmm==0||mmm>m+p[s][i])){
			T[i]=1;
			TSP(p, N, i, n+1, S, m+p[s][i]);
			T[i]=0;
			}
	}
	}
	else if(p[s][S]!=0){
		if(mmm!=0)mmm = min(mmm, m+p[s][S]);
        	else mmm = m+p[s][S];
        }
}
int main(void){
	int N;
	cin >> N;
    T = new int[N];
	int** p = new int*[N];
	for(int i=0; i<N; i++){
		p[i] = new int[N];
		for(int j=0; j<N; j++)
			cin >> p[i][j];
	}
	mmm=0;
	if(N==2){
		cout << p[0][1]+p[1][0];
		return 0;
	}

	for(int i=0; i<N; i++){
			TSP(p,N,i,0,i,0);
	}
	cout << mmm;
	return 0;
}
