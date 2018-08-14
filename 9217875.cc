#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int next(int a){
	a = (a%10000)/1000 + (a%1000)/100 + (a%100)/10 + a%10 + a;
	return a;
}
int main(void){
	int n=1;
	int *a;
	int c=n;
	a = (int*)malloc(sizeof(int)*10000);
	for(int i=0; i<10000; i++)
		a[i]=1;

	while(n<10000){
		c=n;
		while(next(n)<10000){
			a[next(n)]=0;
			n=next(n);		
		}
		n=c+1;
	}
	int l = 1;
	while(1){
		if(a[l]==1)
			cout<<l<<endl;
		l++;
		if(l>9999)
			break;
	}
        free(a);
	return 0;
}
