#include <stdlib.h>
#include <iostream>

using namespace std;

int pow(int a, int b) {
	int r = 1;
	for (int i = 0; i < b; i++)
		r *= a;
	return r;
}
void merge(int* lst, int l, int m, int r) {
	int s = l;
	int s2 = m + 1;
	int* lst2;
	int n = l;
	lst2 = (int*)malloc(sizeof(int)*16);
	while (s <= m&&s2 <= r) {
		if (lst[s] > lst[s2]) {
			lst2[n] = lst[s];
			s++;
		}
		else {
			lst2[n] = lst[s2];
			s2++;
		}
		n++;
	}
	while (s <= m) {
		lst2[n] = lst[s];
		s++;
		n++;
	}
	while (s2 <= r) {
		lst2[n] = lst[s2];
		s2++;
		n++;
	}
	for (int i = l; i <= r; i++)
		lst[i] = lst2[i];
}
void mergeSort(int* lst, int l, int r) {
	if (l < r) {
		int m = (l + r) / 2;
		mergeSort(lst, l, m);
		mergeSort(lst, m + 1, r);
		merge(lst, l, m, r);
	}
}
int main(void) {

	int n;
	cin >> n;
	int* lst;
	lst = (int*)malloc(sizeof(int)*16);
	for (int i = 0; i < 16; i++)
		lst[i] = -1;
	for (int i = 0; i < 16; i++) {
		if (n < pow(10, i))
			break;
		lst[i] = (n % pow(10, i + 1)) / pow(10, i);
	}
	mergeSort(lst, 0, 15);
	for (int i = 0; i < 16; i++)
		if (lst[i] != -1)
			cout << lst[i];
	
	return 0;
}
