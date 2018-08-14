#include <iostream>
#include <stdlib.h>

using namespace std;
typedef struct queue {
	int data;
	struct queue* link;
}queue;
void push(queue* q, int n, queue* q2) {
	queue* nq;
	nq = (queue*)malloc(sizeof(queue));
	nq->data = n;
	nq->link = NULL;
	if (q->link == NULL) {
		q->link = nq;
		q2->link = nq;
		return;
	}
	q2->link->link = nq;
	q2->link = nq;

}
void pop(queue* q, queue* q2) {
	if (q->link == NULL) {
		cout << "-1" << endl;
		return;
	}
	queue* t;
	t = q->link;
	q->link = q->link->link;
	if(q->link == NULL)
		q2->link = NULL;
	cout << t->data << endl;
	free(t);
}
void size(queue* q) {
	queue* t;
	t = q->link;
	int c = 0;
	while (t != NULL) {
		t = t->link;
		c++;
	}
	cout << c << endl;
}
void empty(queue* q) {
	if (q->link == NULL)
		cout << "1" << endl;
	else
		cout << "0" << endl;
}
void front(queue* q) {
	if (q->link == NULL)
		cout << "-1" << endl;
	else
		cout << q->link->data << endl;
}

int main(void) {
	int n;
	cin >> n;
	char** c;
	int* num;
	c = (char**)malloc(sizeof(char*)*n);
	num = (int*)malloc(sizeof(int)*n);
	queue* q1;
	q1 = (queue*)malloc(sizeof(queue));
	q1->data = -1;
	q1->link = NULL;
	queue* q2;
	q2 = (queue*)malloc(sizeof(queue));
	q2->data = -1;
	q2->link = NULL;
	for (int i = 0; i<n; i++) {
		c[i] = (char*)malloc(sizeof(char) * 10);
		cin >> c[i];
		if (c[i][1] == 'u')
			cin >> num[i];
		if (c[i][1] == 'o')
			pop(q1, q2);
		if (c[i][1] == 'u')
			push(q1, num[i], q2);
		if (c[i][1] == 'i')
			size(q1);
		if (c[i][1] == 'm')
			empty(q1);
		if (c[i][1] == 'r')
			front(q1);
		if (c[i][1] == 'a')
			front(q2);
	}
	
	return 0;
}
