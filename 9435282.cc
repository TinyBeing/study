#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int* p;
	int tmp;
	p = (int*)malloc(sizeof(int)*n);
	for(int i=0; i<n; i++)
		cin >> p[i];
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (p[j] < p[i]) {
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
	tmp = 0;
	int t = 0;
	for (int i = 0; i < n; i++) {
		tmp += p[i];
		t += tmp;
	}
	cout << t;

	return 0;
}