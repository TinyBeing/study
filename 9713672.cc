#include <stdlib.h>
#include <iostream>
using namespace std;
int main(void){
	int t;
	cin >> t;
	int n=0;
	char s[20];
	int r;
	char** rc;
	rc = (char**)malloc(sizeof(char*)*t);
	for(int i=0; i<t; i++)
		rc[i]= (char*)malloc(sizeof(char)*160);
	while(n<t){
		cin >> r >> s;
		int j = 0;
		while(s[j] != '\0'){
			for(int i=0; i<r; i++)
				rc[n][i+j*r] = s[j];
			j++;
		}
		
		n++;
	}
	for(int i=0; i<t; i++)
		cout << rc[i] << endl;
	return 0;
}