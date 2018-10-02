#include <iostream>
using namespace std;
int tmp;
bool search(int** t, int a, int f){
	if(a>=0){
		if(a==f){
			if(t[a][0]>=0)
				t[t[a][0]][2] = tmp-1;
			t[a][1]=0;
			return true;
		}
		if(search(t,t[a][0],f)){
			t[a][1]=0;
			return true;
		}
	}
	return false;
}
int main(void){
	int N;
	cin >> N;
	int num;
	int** tree = new int*[N];
	for(int i=0; i<N; i++){
		tree[i] = new int[3];
		tree[i][0]=0;
		tree[i][1]=1;
		tree[i][2]=0;
	}
	for(int i=0; i<N; i++){
		cin >> num;
		tree[i][0] = num;
		if(num>=0){
			tree[num][1] = 0;
			tree[num][2]++;
		}
	}
	int D;
	cin >> D;
	if(tree[D][0]>=0)
		tmp = tree[tree[D][0]][2];
	int sum=0;
	for(int i=0; i<N; i++){
		if(tree[i][1]==1){
			if(search(tree,i,D)&&tree[D][0]!=-1&&tree[tree[D][0]][2]==0){
				tree[tree[D][0]][1] = 1;
			}
		}
	}
	for(int i=0; i<N; i++){
		sum+=tree[i][1];
	}
	cout << sum;
	return 0;
}
