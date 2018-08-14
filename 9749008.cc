#include <stdlib.h>
#include <iostream>
#include <stack>
#include <utility>
using namespace std;
int** co;
int re;
stack<pair<int,int> > q;
inline int make(int** c, int a, int b, int n) {
	int count=0;
	for (int i = 0; i < n; i++) {
		if (c[a][i] == 0) {
			q.push(pair<int, int>(a, i));
			count++;
		    c[a][i] = 1;
        }
	}
	for (int i = a; i < n; i++) {
		if (c[i][b] == 0) {
			q.push(pair<int, int>(i, b));
			count++;
		    c[i][b] = 1;
        }
	}
	int tmp, tmp2;
	tmp = a; tmp2 = b;
	while (tmp < n - 1 && tmp2 < n - 1) {
		if (c[++tmp][++tmp2] == 0) {
			q.push(pair<int, int>(tmp, tmp2));
			count++;
		    c[tmp][tmp2] = 1;
        }
	}
	while (a < n - 1 && b > 0) {
		if (c[++a][--b] == 0) {
			q.push(pair<int, int>(a, b));
			count++;
            c[a][b] = 1;
		}
	}
	return count;
}
inline void make2(int** c,int n) {
	while(n-->0) {
		c[q.top().first][q.top().second] = 0;
		q.pop();
	}
}
inline void track(int** c, int a, int b, int count, int n) {
	if (count == n){ 
		re++;
        return;
    }
	int num = make(c, a, b, n);
	for (int i = 0; i < n; i++)
		if (c[a + 1][i] == 0)
			track(c, a + 1, i, count + 1, n);
	make2(c, num);
}
int main(void) {
	int n;
	cin >> n;
	co = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++)
		co[i] = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			co[i][j] = 0;
    re = 0;
	for (int i = 0; i < n; i++)
		track(co, 0, i, 1, n);
	cout << re << endl;
	return 0;
}
