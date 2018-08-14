#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

int minn(int a, int b){
	if(a>b)
		return b;
	return a;
}

int main(void)
{
	int num;
	int* r;
	int* g;
	int* b;
	int min = 0;
	int* rgb = new int[3];
	int rc;
	int gc;
	int bc;

	cin>>num;

	r = new int[num];
	g = new int[num];
	b = new int[num];

	for(int i=0; i<num; i++){
		cin>>r[i]>>g[i]>>b[i];
	}

	rgb[0] = r[0];
	rgb[1] = g[0];
	rgb[2] = b[0];

	for(int i=1; i<num; i++){
		rc = rgb[0];
		gc = rgb[1];
		bc = rgb[2];
		if(gc>bc)
			rgb[0] = bc + r[i];
		else
			rgb[0] = gc + r[i];
		if(rc>bc)
			rgb[1] = bc + g[i];
		else
			rgb[1] = rc + g[i];
		if(rc>gc)
			rgb[2] = gc + b[i];
		else
			rgb[2] = rc + b[i];
	}

	min = rgb[0];
	if(min>rgb[1])
		min = rgb[1];
	if(min>rgb[2])
		min = rgb[2];

	cout<<min;

	return 0;
}