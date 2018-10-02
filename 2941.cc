#include <iostream>
using namespace std;
int strlen(char* c){
	int count=0;
	while(c[count++]!='\0');
	return count-1;
}
int main(void){
	char c[101];
	cin >> c;
	int count = 0;
	for(int i=0; i<strlen(c); i++){
		count++;
		if(i<strlen(c)-1){
		if(c[i]=='d'){
			if(c[i+1]=='z'){
				if(i+2<strlen(c)&&c[i+2]=='=')
					i += 2;
			}
			else
				i++;
		}
		else if(c[i]=='c'){
			if(c[i+1]=='='||c[i+1]=='-')
				i++;
		}
		else if(c[i]=='l'){
			if(c[i+1]=='j')
				i++;
		}
		else if(c[i]=='n'){
			if(c[i+1]=='j')
				i++;
		}
		else if(c[i]=='s'){
			if(c[i+1]=='=')
				i++;
		}
		else if(c[i]=='z'){
			if(c[i+1]=='=')
				i++;
		}
		}
	}
	cout << count;
	return 0;
}
