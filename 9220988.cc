#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;
int min(int a, int b, int c){
	int tmp = a;
	if(tmp>b)
		tmp = b;
	if(tmp>c)
		tmp = c;
	return tmp;
}
int min2(int a, int b){
	if(a>b)
		return b;
	return a;
}
int fast(int n, int* l){
	if(n==1)
		return 0;
	if(n%3==0){
		if(n%2==0)
			return 1 + min(l[n/3],l[n/2],l[n-1]);
		return 1 + min2(l[n/3],l[n-1]);
	}
	if(n%2==0)
		return 1 + min2(l[n/2],l[n-1]);
	return 1 + l[n-1];	
}
int main(){
	int x;
	int* l;
	
	cin>>x;

	l = (int*)malloc(sizeof(int)*(x+1));
	for(int i=1; i<x+1; i++){
		l[i] = fast(i,l);
	}
	cout<<l[x]<<endl;
	return 0;
}
