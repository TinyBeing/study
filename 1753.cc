#include <cstdio>
#include <queue>
#include <utility>
#include <functional>
#include <vector>
using namespace std;
struct point {
	int val;
	int u;
};
bool operator < (point a, point b) {
	return a.val > b.val;
}
int main(void) {
	int V, E, K;
	int x, y;
	scanf("%d %d", &V, &E);
	scanf("%d", &K);
	int* dp = new int[V + 1];
	vector<vector<pair<int,int> > > v;
	v.resize(V+1);
	for (int i = 1; i <= V; i++) {
		dp[i] = 0;
		v[i].resize(1);
	}
	point p;
	int w;
	for (int i = 0; i<E; i++) {
		scanf("%d %d %d", &x, &y, &w);
		v[x].push_back(make_pair(y,w));
		v[x].resize(v[x].size());
	}
	int u;
	queue<point> pq;
	do {
		if (!pq.empty()) {
			u = pq.front().u;
			pq.pop();
		}
		else
			u = K;
		for(int i=0; i<v[u].size(); i++) {
			if ((dp[v[u][i].first] > dp[u] + v[u][i].second || dp[v[u][i].first] == 0)) {
				dp[v[u][i].first] = dp[u] + v[u][i].second;
				p.u = v[u][i].first; p.val = v[u][i].second;
				pq.push(p);
			}
		}
	} while (!pq.empty());
	for (int i = 1; i <= V; i++) {
		if (i == K)
			printf("0\n");
		else {
			if (dp[i] != 0)
				printf("%d\n", dp[i]);
			else
				printf("INF\n");
		}
	}
	return 0;
}

