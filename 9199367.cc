#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){

	char *a;
	a = new char[100];
	cin>>a;

	for(int i = 0; i<10; i++){
		for(int f = 0; f<10; f++){
			if(!a[f+i*10])
				break;
			cout<<a[f+i*10];
		}
		if(!a[i*10])
			break;
		cout<<endl;
	}

	

	return 0;


}
