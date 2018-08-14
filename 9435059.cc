#include <iostream>
#include <stdlib.h>
using namespace std;
void push(char* q, char n) {
	int i = 0;
	while (q[i] != 'Z')
		i++;
	q[i] = n;
}
char pop(char* q, int n) {
	char r;
	r = q[0];
	int i = 0;
	for (i; i < n - 1; i++)
		q[i] = q[i + 1];
	q[n - 1] = 'Z';
	return r;
}

int main(void)
{
	int n;
	cin >> n;
	int tmp = 0;
	char* p;
	char* t;
	p = (char*)malloc(sizeof(char) * 51);
	t = (char*)malloc(sizeof(char) * 51);
	int* tc;
	tc = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		tc[i] = 1;
	while (tmp < n) {
		for (int i = 0; i < 51; i++) {
			p[i] = 'Z';
			t[i] = 'Z';
		}
		cin >> p;
		char c;
		int l = 0;
		while (p[l] != 'Z' && l < 51) {
			if (p[l] == '(')
				push(t, '(');
			if (p[l] == ')') {
				c = pop(t, 51);
				if (c != '(') {
					tc[tmp] = 0;
					break;
				}
			}
			l++;
		}
		if (t[0] != 'Z')
			tc[tmp] = 0;
		tmp++;
	}
	for (int i = 0; i < n; i++) {
		if (tc[i] == 0)
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}

	return 0;
}