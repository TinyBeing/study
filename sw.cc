#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;
void del(int** lst, int a, int** gp, int x, int y, int N){
	for(int i=0; i<3; i++){
		for(int j=0; j<N; j++){
			if(gp[i][j]==a){
				for(int k=0; k<3; k++){
					if(gp[k][j]!=-1&&k!=i){
						gp[k][j]=-1;
						del(lst, gp[k][j], gp, k, j, N);
					}	
				}
			}
		}
	}
}
int main(void){
	int T;
	int count;
	scanf("%d", &T);
	int** gp;
	int N;
	int** lst;
	for(int n=1; n<=T; n++){
		count = 0;
		scanf("%d", &N);
		lst = (int**)malloc(sizeof(int*)*3);
		for(int i=0; i<N; i++){
			lst[i] = (int*)malloc(sizeof(int)*N);
			lst[i] = {0};
		}		
		gp = (int**)malloc(sizeof(int*)*3);
		for(int i=0; i<3; i++){
			gp[i] = (int*)malloc(sizeof(int)*N);
			for(int j=0; j<N; j++)
				scanf("%d", &gp[i][j]);
		}
		for(int i=0; i<3; i++)
			for(int j=0; j<N; j++)
				lst[gp[i][j]][i]++;
		for(int i=0; i<3; i++)
			for(int j=0; j<N; j++){
				if(lst[0][gp[i][j]]+lst[1][gp[i][j]]+lst[2][gp[i][j]]<3)
					del(lst, gp[i][j], gp, i, j, N);
			}
		for(int i=0; i<N; i++){
			if(gp[0][i]!=-1)
				count++;
		}
		cout << "#" << T << " " << count << endl;
	}
	return 0;
}
