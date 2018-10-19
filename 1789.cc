#include <iostream>
using namespace std;
int main(void){
	double S;
	cin >> S;
	int count=1;
	while(S>0){
		S-=count;
		if(S<0)
			break;
		count++;
	}
	cout << count-1;
	return 0;
}
