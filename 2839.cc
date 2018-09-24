#include <iostream>
using namespace std;
int main(void){
	int N;
	int R=0;
	cin >> N;
	while(N%5!=0){
		N-=3;
		R++;
		if(N<0){
			cout << "-1";
			return 0;
		}
	}
	R += N/5;
	cout << R;
	return 0;
}
