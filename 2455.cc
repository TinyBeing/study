#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
	int a, b;
	int M=0;
	for(int i=0; i<4; i++){
		cin >> a >> b;
		M = max(M, M+b-a);
	}
	cout << M;
	return 0;
}
