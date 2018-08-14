#include <stdlib.h>
#include <iostream>
using namespace std;
long long int fact(int a, long long int b){
	if (a < 1)
		return b;
	return fact(a - 1, b*a);
}
long long int fact2(int a, int b, long long int c) {
	if (a <= b)
		return c;
	return fact2(a - 1, b, c*a);
}
long long int com(int a, int b) {
	if (a / 2 + 1 > b)
		return fact2(a, a - b, 1) / fact(b, 1);
	else
		return fact2(a, b, 1) / fact(a - b, 1);
}
int main(void) {
	int t;
	cin >> t;
	int n;
	int m;
	int num = 0;
	long long int* r;
	r = (long long int*)malloc(sizeof(long long int)*t);
	while (num < t) {
		cin >> n >> m;
		r[num] = com(m, n);
		num++;
	}
	for (int i = 0; i < t; i++)
		cout << r[i] << endl;

	return 0;
}
