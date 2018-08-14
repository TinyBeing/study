#include <iostream>
#include <stdlib.h>

using namespace std;

int main(void){
	int k[9];
	for(int i=0; i<9; i++)
		cin >> k[i];
	int s=0;
	for(int i=0; i<9; i++)
		s += k[i];
	if(s==100){
		for(int i=0; i<101; i++)
			for(int j=0; j<7; j++)
				if(i==k[j])
					cout << k[j] << endl;
		return 0;
	}
	int a,b,c;
	c=0;
	for(int i=0; i<8; i++){
		for(int j=i+1; j<9; j++)
			if(s-k[i]-k[j]==100){
				a = i;
				b = j;
				c = 1;
				break;
			}
		if(c==1)
			break;
	}
	k[a] = 101;
	k[b] = 101;
	for(int i=0; i<101; i++)
			for(int j=0; j<9; j++)
				if(i==k[j])
					cout << k[j] << endl;
	return 0;
}
