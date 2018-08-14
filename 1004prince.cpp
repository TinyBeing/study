#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int sq(int i){return i*i;}
int main(void)
{
	int tcase=0;
	int rx,ry;
	int dx,dy;
	int num=0;
	int *px,*py,*pr;
	int count=0;
	int* tc;
	int t=0;

	cin>>tcase;
	tc = new int[tcase];

	while(t<tcase){
		cin>>rx;
		cin>>ry;
		cin>>dx;
		cin>>dy;
		cin>>num;
		px = new int[num];
		py = new int[num];
		pr = new int[num];
		for(int i=0; i<num; i++){
			cin>>px[i];
			cin>>py[i];
			cin>>pr[i];
		}
		for(int i=0; i<num; i++){
			if(sq(px[i]-rx)+sq(py[i]-ry)<sq(pr[i])){
				if(sq(px[i]-dx)+sq(py[i]-dy)<sq(pr[i]))
					;
				else
					count++;
			}
			else
				if(sq(px[i]-dx)+sq(py[i]-dy)<sq(pr[i]))
					count++;
		}
		tc[t] = count;
		count = 0;
		t++;		
	}

	for(int i=0; i<tcase; i++)
		cout<<tc[i]<<endl;

	return 0;
}
