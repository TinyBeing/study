#include <iostream>

using namespace std;

int num(int a,int b,int c){
	if(a>=b)
		return c;
	return num(a+c*6,b,c+1);
}
int main(void)
{
	int n;
	cin>>n;
	cout<<num(1,n,1);
	return 0;
}

