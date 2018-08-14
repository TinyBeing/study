#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void)
{
	int n;
	int* num;
	int* prime;
	cin >> n;
	int count = 0;
	prime = (int*)malloc(sizeof(int)*1001);
	prime[0] = 0;
	prime[1] = 0;
	for (int j = 2; j < 1001; j++)
		prime[j] = 1;
	for (int j = 2; j < 1001; j++) {
		if (prime[j] == 1) {
			for (int i = j+1; i < 1001; i++)
				if (i%j == 0) {
					prime[i] = 0;
				}
		}
	}
	num = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		cin >> num[i];
	for (int i = 0; i < n; i++) {
		int tmp = 0;
		while (tmp != num[i])
			tmp++;
		if (prime[tmp] == 1 && tmp == num[i])
			count++;
	}
	cout << count;


	return 0;
}
