#include <iostream>
#include <cstdio>
float di(float a){
	while(a>=10007){
		a-=10007;
	}
	return a;
}
using namespace std;
int main(void){
	long long N,K;
	cin >> N >> K;
	float r=1;
	float j=K;
	if(N-K>N/2){
		j=K;
		for(float i=N; i>N-K; i=i-1){
			
			printf("%lf\n", i/j);

			if(i!=0)
				r = di(r*(i/j));
			j=j-1;
		}
	}
	else{
		j=N-K;
		for(float i=N; i>K; i=i-1){
			printf("%lf\n", i/j);
			if(i!=0)
				r = di(r*(i/j));
			j=j-1;
		}
	}
	cout << r;
	return 0;
}
