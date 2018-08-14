#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

int main(void){
	
	char* s;
	s = (char*)malloc(sizeof(char)*100);

	cin>>s;

	int* al;
	al = (int*)malloc(sizeof(int)*26);
	for(int i=0;i<26;i++)
		al[i] = -1;
	int i = 0;
	while(s[i]!='\0'){
	
		if(s[i] == 'a'&&al[0]<0)
			al[0] = i;
		if(s[i] == 'b'&&al[1]<0)
			al[1] = i;
		if(s[i] == 'c'&&al[2]<0)
			al[2] = i;
		if(s[i] == 'd'&&al[3]<0)
			al[3] = i;
		if(s[i] == 'e'&&al[4]<0)
			al[4] = i;
		if(s[i] == 'f'&&al[5]<0)
			al[5] = i;
		if(s[i] == 'g'&&al[6]<0)
			al[6] = i;
		if(s[i] == 'h'&&al[7]<0)
			al[7] = i;
		if(s[i] == 'i'&&al[8]<0)
			al[8] = i;
		if(s[i] == 'j'&&al[9]<0)
			al[9] = i;
		if(s[i] == 'k'&&al[10]<0)
			al[10] = i;
		if(s[i] == 'l'&&al[11]<0)
			al[11] = i;
		if(s[i] == 'm'&&al[12]<0)
			al[12] = i;
		if(s[i] == 'n'&&al[13]<0)
			al[13] = i;
		if(s[i] == 'o'&&al[14]<0)
			al[14] = i;
		if(s[i] == 'p'&&al[15]<0)
			al[15] = i;
		if(s[i] == 'q'&&al[16]<0)
			al[16] = i;
		if(s[i] == 'r'&&al[17]<0)
			al[17] = i;
		if(s[i] == 's'&&al[18]<0)
			al[18] = i;
		if(s[i] == 't'&&al[19]<0)
			al[19] = i;
		if(s[i] == 'u'&&al[20]<0)
			al[20] = i;
		if(s[i] == 'v'&&al[21]<0)
			al[21] = i;
		if(s[i] == 'w'&&al[22]<0)
			al[22] = i;
		if(s[i] == 'x'&&al[23]<0)
			al[23] = i;
		if(s[i] == 'y'&&al[24]<0)
			al[24] = i;
		if(s[i] == 'z'&&al[25]<0)
			al[25] = i;
		i++;
	}
	for(int i=0; i<26; i++)
		cout<<al[i]<<" ";
	return 0;
}
