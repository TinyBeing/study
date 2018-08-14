#include <iostream>
#include <stdlib.h>

using namespace std;
typedef struct queue {
	int data;
	struct queue* link;
}queue;

void qpush(queue* t, int n, queue* t2) {
	queue* tmp;
	if (t->link == NULL) {
		queue* newq = (queue*)malloc(sizeof(queue));
		newq->data = n;
		newq->link = NULL;
		t->link = newq;
		t2->link = newq;
		return;
	}
	tmp = t2->link;
	queue* newq = (queue*)malloc(sizeof(queue));
	newq->data = n;
	newq->link = NULL;
	tmp->link = newq;
	t2->link = newq;
}
int qpop(queue* t) {
	queue* tmp;
	tmp = t->link;
	int r = tmp->data;
	t->link = tmp->link;
	free(tmp);
	return r;
}

int main(void)
{
	int* n;
	int a;
	int b;
	cin >> a >> b;
	n = (int*)malloc(sizeof(int)*100001);
	for (int i = 0; i < 100001; i++)
		n[i] = -1;
	n[a] = 0;
	queue* q2 = (queue*)malloc(sizeof(queue));
	queue* q = (queue*)malloc(sizeof(queue));
	q->data = -1;
	q->link = NULL;
	q2->data = -1;
	q2->link = NULL;
	int tmp;
	qpush(q, a, q2);
	n[a] = 0;
	while (q->link != NULL) {
		tmp = qpop(q);
		if (tmp != 0 && tmp <= 50000 && (n[tmp * 2] > n[tmp] + 1 || n[tmp * 2] == -1) && (n[tmp] < n[b] || n[b] == -1) && tmp < b)
		{
			n[tmp * 2] = n[tmp] + 1;
			qpush(q, tmp * 2, q2);
		}
		if (tmp > 0 && (n[tmp - 1] > n[tmp] + 1 || n[tmp - 1] == -1) && (n[tmp] < n[b] || n[b] == -1))
		{
			n[tmp - 1] = n[tmp] + 1;
			qpush(q, tmp - 1, q2);
		}
		if (tmp < 100001 && (n[tmp + 1] > n[tmp] + 1 || n[tmp + 1] == -1) && (n[tmp] < n[b] || n[b] == -1) && tmp < b)
		{
			n[tmp + 1] = n[tmp] + 1;
			qpush(q, tmp + 1, q2);
		}
	
	}
	cout << n[b];

	return 0;
}