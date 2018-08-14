#include <stdlib.h>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
pair<int, int> loc(int a, int b, int n) {
	if (n == 0)
		return pair<int, int>(a - 1, b);
	if (n == 1)
		return pair<int, int>(a, b - 1);
	if (n == 2)
		return pair<int, int>(a + 1, b);
	if (n == 3)
		return pair<int, int>(a, b + 1);
}
bool isin(int a, int b, int c, int d) {
	return a > -1 && b > -1 && a < c && b < d;
}

int main(void) {
	int n;
	int m;
	cin >> m >> n;
	int** t;
	int** check;
	queue<pair <int, int> > q;
	check = (int**)malloc(sizeof(int*)*n);
	t = (int**)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++) {
		t[i] = (int*)malloc(sizeof(int)*m);
		check[i] = (int*)malloc(sizeof(int)*m);
	}
	int c = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			check[i][j] = 0;
			cin >> t[i][j];
			c += t[i][j];
		}
	int day = 0;
	if (c == n * m) {
		cout << day;
		return 0;
	}
	c = 0;
	int x, y;
	int x2, y2;
	int count = 0;
	int tmp;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (check[i][j] == 0 && t[i][j] == 1) {
				q.push(pair<int, int>(i, j));
				count++;
			}
	tmp = count;
	do{
		count = 0;
		while (tmp>0) {
			x = q.front().first;
			y = q.front().second;
			q.pop();
			tmp--;
			for (int i = 0; i < 4; i++) {
				x2 = loc(x, y, i).first;
				y2 = loc(x, y, i).second;
				if (isin(x2,y2,n,m) && t[x2][y2] > -1 && check[x2][y2] == 0) {
					t[x2][y2] = 1;
					q.push(pair<int, int>(x2, y2));
                    check[x2][y2] = 1;
					count++;
				}
			}
		}
		tmp = count;
		day++;
	} while (tmp != 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (t[i][j] == 0)
				c = 1;
	if(c != 1)
		cout << day-1;
	else cout << -1;
	return 0;
}
