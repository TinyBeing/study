#include <stdio.h>
#include <stdlib.h>

int main(){
	int a;
	scanf("%d",&a);
	int b=a;
	int c=0;
	int cycle=0;

	if(a>=0&&a<100){
		do{
			c=b%10+b/10;
			b=c%10+(b%10)*10;
			cycle++;
		
		}while(a!=b);
		printf("%d",cycle);
	}

	

	return 0;


}
