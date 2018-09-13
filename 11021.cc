#include <iostream>
#include <stdlib.h>
using namespace std;
int main(void){
	int n;
	int a, b;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a >> b;
		cout << "Case #" << i <<": " << a+b<< endl;
	}
	return 0;
}
