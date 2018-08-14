#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(){
	int A;
	int B;
	int C;
	cin>>A;
	cin>>B;
	cin>>C;

	int *set;
	set = new int[10];

    if(A>=100&&A<1000&&B>=100&&B<1000&&C>=100&&C<1000){
	for(int i=0; i<10; i++)
		set[i]=0;
	for(int i=0; i<10; i++){
		for(int z=1; z<1000000000; z*=10){
			if(A*B*C>z){
			if((A*B*C%(10*z))/z == i)
				set[i]+=1;
			}
		}
	}
    
	
	for(int i=0; i<10; i++)
		cout<<set[i]<<endl;
    }
	return 0;


}
