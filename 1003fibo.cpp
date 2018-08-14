#include <stdlib.h>
#include <iostream>

using namespace std;
int lst[41];
int lst2[41];
void fibonacci(int n) {
	if (n == 0) {
		lst[n]++;
		return;
	}
	else if (n == 1) {
		lst2[n]++;
		return;
	}
	else {
		lst[n] = lst[n - 1] + lst[n - 2];
		lst2[n] = lst2[n - 1] + lst2[n - 2];
		return;
	}
}

int main(void) {

	int n;
	cin >> n;
	int* t;
	int* r;
	int* r2;
	r = (int*)malloc(sizeof(int)*n);
	r2 = (int*)malloc(sizeof(int)*n);
	t = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < 41; i++) {
		fibonacci(i);
	}
	for (int i = 0; i < n; i++)
		cin >> t[i];
	for (int i = 0; i < n; i++) {
		r[i] = lst[t[i]];
		r2[i] = lst2[t[i]];
	}
	for (int i = 0; i < n; i++)
		cout << r[i] << " " << r2[i] << endl;
	return 0;
}

