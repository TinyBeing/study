#include <iostream>
#include <stdlib.h>
using namespace std;

int main(void)
{
	int* n;
	n = (int*)malloc(sizeof(int) * 8);
	for (int i = 0; i < 8; i++)
		cin >> n[i];
	int c = 0;
    c = 1;
	for (int i = 0; i < 8; i++)
		if (n[i] != i + 1)
			c = 0;
	if (c == 0){
        c = 2;
		for (int i = 0; i < 8; i++)
			if (n[i] != 8-i)
				c = 0;
    }
	if (c == 0)
		cout << "mixed";
	if (c == 1)
		cout << "ascending";
	if (c == 2)
		cout << "descending";
	
	return 0;
}
