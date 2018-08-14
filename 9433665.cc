#include <iostream>
#include <stdlib.h>
using namespace std;
void push(int* q, int n) {
	int i = 0;
	while (q[i] != -1)
		i++;
	q[i] = n;
}
int pop(int* q, int n) {
	int r;
	r = q[0];
	int i = 0;
	for (i; i < n-1; i++)
		q[i] = q[i + 1];
	q[n - 1] = -1;
	return r;
}
int main(void)
{
	int n;
	int c;
	cin >> n >> c;
	int count = 0;
	int** com;
	com = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++) {
		com[i] = (int*)malloc(sizeof(int)*n);
		for (int j = 0; j < n; j++)
			com[i][j] = 0;
	}
	int a;
	int b;
	for (int i = 0; i < c; i++) {
		cin >> a >> b;
		a--;
		b--;
		com[a][b] = 1;
		com[b][a] = 1;
	}
	int* check;
	check = (int*)malloc(sizeof(int)*n);
	
	int tmp = 0;
	int* q;
	q = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		q[i] = -1;
		check[i] = 1;
	}
	push(q, 0);
	check[0] = 0;
	while (q[0] != -1) {
		tmp = pop(q, n);
		for(int i=0; i<n; i++){
			if (com[tmp][i] == 1) {
				com[tmp][i] = 0;
				com[i][tmp] = 0;
				if(check[i]==1)
					count++;
				check[i] = 0;
				push(q, i);
			}
		}
	}

	cout << count;

	return 0;
}

