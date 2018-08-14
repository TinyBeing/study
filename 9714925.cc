#include <stdlib.h>
#include <iostream>
using namespace std;
long long fibo(int n, int a, int b) {
	if (n < 2)
		return b;
	return fibo(n-1, b%10007, (a + b)%10007);
}
int main(void) {
	int n;
	cin >> n;
	long long r = 0;
	r = fibo(n, 1, 1);
	cout << r << endl;
	
	return 0;
}
