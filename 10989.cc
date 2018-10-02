#include <cstdio>
int lst[10001] = { 0,};
int main(void){
	int N;
	scanf("%d", &N);
	int a;
	for(int i=0; i<N; i++){
		scanf("%d", &a);
		lst[a]++;
	}
	for(int i=0; i<=10000; i++){
		while(lst[i]>0){
			printf("%d\n", i);
			lst[i]--;
		}
	}
	return 0;
}
