#include <stdio.h>
#include <iostream>


using namespace std;


int main(void)
{
	int n;
	int count=0;
	int a=0;
	int b=0;
	int c=0;
	cin>>n;

	for(int i=1; i<n+1; i++){
		a = i/100;
		b = (i%100)/10;
		c = i%10;
		if(i<100)
			count++;
		else{
			if(a-b == b-c)
				count++;
		}
	}
	cout<<count;

	return 0;
}
