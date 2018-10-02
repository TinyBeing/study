#include <iostream>
#include <algorithm>
using namespace std;
int pushback(int* q, int N) {
	int tmp = q[0];
	for (int i = 0; i < N - 1; i++) {
		q[i] = q[i + 1];
	}
	q[N - 1] = tmp;
	return q[0];
}
int main(void) {
	int T;
	int N, M;
	cin >> T;
	while (T-->0) {
		int tmp;
		int Max = 0;
		int Max2 = 0;
		int count = 0;
		cin >> N >> M;
		tmp = M;
		int* q = new int[N];
		for (int i = 0; i<N; i++)
			cin >> q[i];
		while (1) {
			count++;
			Max = 0;
			for (int i = 1; i<N; i++) {
				if (q[Max]<q[i])
					Max = i;
			}
			if (Max == tmp)
				break;
			Max2 = q[Max];
			if(Max!=0){
			while (1) {
				int t = pushback(q, N);
				if (tmp == 0)
					tmp = N - 1;
				else
					tmp--;
				if (t == Max2)
					break;
			}
			}
			pushback(q, N);
			N--;
			tmp--;
		}
		cout << count << endl;
		delete(q);
	}
	return 0;
}
