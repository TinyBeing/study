#include <iostream>
#include <stdlib.h>

using namespace std;
int lst[11];
int main(void){
	int t;
	cin >> t;

	int* r;
	r = (int*)malloc(sizeof(int)*t);
	
	int i = 0;
	for(int j = 0; j < 11; j++)
		lst[j] = 0;
	lst[0] = 0;
	lst[1] = 1;
	lst[2] = 2;
	lst[3] = 4;
	for(int j = 4; j < 11; j++)
	{
		lst[j] = lst[j] + lst[j-3] + lst[j-2] + lst[j-1];
	}
	int k;
	while(i<t){
		cin >> k;
		r[i] = lst[k];      	
		i++;
	}	
	for(int j = 0; j < t; j++)
		cout<<r[j]<<endl;
	return 0;
}