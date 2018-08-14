#include <iostream>
#include <stdlib.h>

using namespace std;

int main(void){
	int n;
	cin >> n;
	long long* t;
	char* r;
	t = (long long*)malloc(sizeof(long long)*n+1);
	
	for(int i=0; i<n+1; i++)
		t[i] = 0;

	t[1] = 1;
	t[0] = 1;
	for(int i=2; i<n+1; i++)
		for(int j=0; j<i-1; j++)
			t[i] += t[j];
	cout << t[n];
	return 0;
}
