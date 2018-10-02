#include <iostream>
using namespace std;
int strlen(char* c){
	int count=0;
	while(c[count]!='\0')count++;
	return count;
}
int main(void){
	int N;
	cin >> N;
	int n;
	char f[51];
	char cm[51];
	for(int i=0; i<N; i++){
		if(i==0)
			cin >> cm;
		else{
			cin >> f;
			for(int j=0; j<strlen(f); j++)
				if(cm[j]!=f[j])
					cm[j] = '?';
		}
	}
	cout << cm;
	return 0;
}
