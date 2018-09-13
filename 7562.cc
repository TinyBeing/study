#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
#include <queue>
#include <utility>


bool inside(int x, int y, int n) {
	return (x <= n && x >= 0 && y <= n && y >= 0);
}
bool check(int x, int y, int** c) {
	if (c[x][y] == 0)
		return true;
	return false;
}
int main(void) {
	int T;
	cin >> T;
	int l;
	int** chess;
	int x, y;
	int dx, dy;
	for (int k = 0; k<T; k++) {
		queue<pair<int, int> > q;
		queue<int> q2;
		int r = 0;
		cin >> l;
		chess = (int**)malloc(sizeof(int*)*l);
		for (int i = 0; i<l; i++) {
			chess[i] = (int*)malloc(sizeof(int)*l);
			for (int j = 0; j<l; j++)
				chess[i][j] = 0;
		}
		cin >> x >> y >> dx >> dy;
		q.push(make_pair(x,y));
		chess[x][y] = 1;
		q2.push(r);
		while (!q.empty()) {  
			r = q2.front();
			q2.pop();
			x = q.front().first;
			y = q.front().second;
			if (x == dx && y == dy)
				break;
			q.pop();
			if (inside(x + 2, y + 1, l - 1) && check(x + 2, y + 1, chess)) {
				q.push(make_pair(x+2, y+1));
				q2.push(r + 1);
				chess[x+2][y+1] = 1;
			}
			if (inside(x + 1, y + 2, l - 1) && check(x + 1, y + 2, chess)) {
				q.push(make_pair(x+1, y+2));
				q2.push(r + 1);
				chess[x+1][y+2] = 1;
			}
			if (inside(x - 1, y - 2, l - 1) && check(x - 1, y - 2, chess)) {
				q2.push(r + 1);
				chess[x-1][y-2] = 1;
				q.push(make_pair(x-1, y-2));
			}
			if (inside(x - 2, y - 1, l - 1) && check(x - 2, y - 1, chess)) {
				q.push(make_pair(x-2, y-1));
				q2.push(r + 1);
				chess[x-2][y-1] = 1;
			}
			if (inside(x - 2, y + 1, l - 1) && check(x - 2, y + 1, chess)) {
				q2.push(r + 1);
				chess[x-2][y+1] = 1;
				q.push(make_pair(x-2, y+1));
			}
			if (inside(x - 1, y + 2, l - 1) && check(x - 1, y + 2, chess)) {
				q2.push(r + 1);
				chess[x-1][y+2] = 1;
				q.push(make_pair(x - 1, y + 2));
			}
			if (inside(x + 2, y - 1, l - 1) && check(x + 2, y - 1, chess)) {
				q2.push(r + 1);
				chess[x+2][y-1] = 1;
				q.push(make_pair(x + 2, y - 1));
			}
			if (inside(x + 1, y - 2, l - 1) && check(x + 1, y - 2, chess)) {
				q2.push(r + 1);
				chess[x+1][y-2] = 1;
				q.push(make_pair(x + 1, y - 2));
			}
		}
		for (int i = 0; i < l; i++)
			free(chess[i]);
		free(chess);
		cout << r << endl;
	}
	return 0;

}



