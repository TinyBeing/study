#include <stdlib.h>
int main(){
	char st[] = "string1";
	char* st2 = "string2";
	const char* st3 = "string3";
	char* const st4 = "string4";
	st = "stringX";
	//st2[0] = 'X';
	st3[1] = 'X';
	st4[0] = 'X';
	st4 = "new string";
	return 0;
}
