#include <cstdio>
int palzin(int n){
	int r = 0;
	int tmp = 1;
	while(n){
		r += tmp*(n%10);
		tmp *= 10;
		n /= 10;
	}
	return r;
}
int main(){
	int N;
	scanf("%d", &N);
	int* lst = new int[N];
	for(int i=0; i<N; i++)
		scanf("%d", *lst[i]);
	for(int i=0; i<N; i++){
		lst[i] = palzin(lst[i]);
	}
	int tmp=0;
	int c;
	for(int i=0; i<3; i++){
		for(int j=0; j<N; j++){
			for(int k=0; k<9; k++){
				if(k==lst[i]%10:
			}
		}
	}		
}
