#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int sq(int i){return i*i;}
int main(void)
{
	int hp,mp;
	int atk;
	int def;
	int tc;
	int ihp,imp;
	int iatk;
	int idef;
	int *stat;

	cin>>tc;

	stat = new int[tc];

	for(int i=0; i<tc; i++){
		cin>>hp;
		cin>>mp;
		cin>>atk;
		cin>>def;
		cin>>ihp;
		cin>>imp;
		cin>>iatk;
		cin>>idef;
		hp = hp+ihp;
		mp = mp+imp;
		atk = atk+iatk;
		def = def+idef;
		if(hp<1)
			hp = 1;
		if(mp<1)
			mp = 1;
		if(atk<0)
			atk = 0;
		stat[i] = hp + 5*mp + 2*atk + 2*def;
	}
	for(int i=0; i<tc; i++)
		cout<<stat[i]<<endl;


	return 0;
}