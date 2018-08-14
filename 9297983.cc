#include <stdio.h>
#include <iostream>


using namespace std;

int fibo(int a, int b, int n){
	if(n==0)
		return a;	
	return fibo(b,a+b,n-1);
}
int main(void)
{
	int num;
	cin>>num;

	cout<<fibo(0,1,num);


	return 0;
}
