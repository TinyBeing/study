#include <iostream>
using namespace std;
int lst[26] = {0,};
int strlen(char* c){
	int count=0;
	while(c[count]!='\0')count++;
	return count;
}
int main(void){
	char S[100];
	cin >> S;
	for(int i=0; i<strlen(S); i++)
		lst[S[i]-'a']++;
	for(int i=0; i<26; i++)
		cout << lst[i] << " ";
	return 0;
}
