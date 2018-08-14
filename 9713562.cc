#include <stdlib.h>
#include <iostream>

using namespace std;
int main(void) {
	char c[1000000];
	cin >> c;
	int num[26] = { 0 };
	int t;
	int j = 0;
	while (c[j] != '\0') {
		t = c[j] - 65;
		if (t>26)
			num[t - 32]++;
		else
			num[t]++;
		j++;
	}
	int max = 0;
	int co = 0;
	for (int i = 1; i<26; i++) {
		if (num[max]<num[i])
		{
			max = i;
			co = 0;
		}
		else 
			if (num[max] == num[i])
				co++;
	}
	if (co>0)
		cout << "?";
	else
		cout << (char)('A' + max);
	return 0;
}