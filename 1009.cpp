#include <iostream>
#include <stdlib.h>

using namespace std;

int pow(int a, int b){
	int r=1;
	a %= 10;
	for(int i=0; i<b; i++){
		r *= a;
		r %= 10;
	}
	return r;
}
int main(void){
	int n;
	cin>>n;

	int* a;
	int* b;
	int* c;
	a = (int*)malloc(sizeof(int)*n);
	b = (int*)malloc(sizeof(int)*n);
	c = (int*)malloc(sizeof(int)*n);
	for(int i=0; i<n; i++)
		cin>>a[i]>>b[i];
	for(int i=0; i<n; i++){
		c[i] = pow(a[i],b[i]);
		c[i] %= 10;
		if(c[i]==0)
			c[i]=10;
	}
	for(int i=0; i<n; i++)
		cout<<c[i]<<endl;
	

	return 0;
}
