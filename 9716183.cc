#include <stdlib.h>
#include <iostream>
using namespace std;

int main(void) {
	int n;
	cin >> n;
	int a = 1;
	int b = 1;
	int count = 1;
	int level = 1;
	while (count < n) {
		if ((a + b) % 2 == 1) {
			while (a < level) {
				a++;
				b--;
				count++;
				if (count == n)
					goto End;
			}
			a++;
			count++;
		}
		else {
			while (b < level) {
				a--;
				b++;
				count++;
				if (count == n)
					goto End;
			}
			b++;
			count++;
		}
		level++;
	}
	End:
	cout << a << "/" << b;
	return 0;
}
