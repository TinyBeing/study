#include <iostream>
#include <stdlib.h>

using namespace std;

int main(void){
	int t;
	cin >> t;
	int** tri;

	tri = (int**)malloc(sizeof(int*)*t);

	for(int i=0; i<t; i++)
		tri[i] = (int*)malloc(sizeof(int)*(i+1));

	for(int i=0; i<t; i++)
		for(int j=0; j<i+1; j++)
			cin >> tri[i][j];
	int k=1;

	while(k<t){
		if(k==1){
			tri[k][0] += tri[0][0];
			tri[k][1] += tri[0][0];
		}
		else
		for(int j=0; j<k+1; j++){
			if(j==k)
				tri[k][j] += tri[k-1][j-1];
			else if(j==0)
				tri[k][j] += tri[k-1][j];
			else if(tri[k-1][j]<tri[k-1][j-1])
				tri[k][j] += tri[k-1][j-1];
			else
				tri[k][j] += tri[k-1][j];
		}
		k++;
	}
	int r = 0;
	for(int i=0; i<t; i++)
		if(r<tri[t-1][i])
			r = tri[t-1][i];
	cout << r;
	return 0;
}
