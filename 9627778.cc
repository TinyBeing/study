#include <iostream>
#include <stdlib.h>
using namespace std;
typedef struct queue {
	int data;
	struct queue* link;
}queue;
queue* q;
queue* q2;
queue* q3;
queue* q4;
void init(queue** q) {
	*q = (queue*)malloc(sizeof(queue));
	(*q)->data = -1;
	(*q)->link = NULL;
}
void push(queue* q, int data, queue* q2) {
	queue* nq;
	nq = (queue*)malloc(sizeof(queue));
	nq->data = data;
	nq->link = NULL;
	if (q->link == NULL) {
		q->link = nq;
		q2->link = nq;
		return;
	}
	q2->link->link = nq;
	q2->link = nq;
	return;
}
int pop(queue* q, queue* q2) {
	queue* tmp;
	if (q->link == NULL)
		return -1;
	tmp = q->link;
	q->link = tmp->link;
	if (q->link == NULL) {
		q2->link = NULL;
	}
	int r;
	r = tmp->data;
	free(tmp);
	return r;
}
int** pc;
int tra2(char** p, int a, int b) {
	int x = 0;
	int y = 0;
	
	pc[x][y] = 1;

	push(q, 0, q2);
	push(q3, 0, q4);
	do {
		x = pop(q, q2);
		y = pop(q3, q4);
		if (x == a - 1 && y == b - 1)break;
		if (x < a - 1)
			if (p[x + 1][y]-48 == 1 && (pc[x + 1][y] == 0 || pc[x + 1][y] > pc[x][y]+1)) {
				push(q, x+1, q2);
				push(q3, y, q4);
				pc[x + 1][y] = pc[x][y] + 1;
			}
		if (y < b - 1)
			if (p[x][y + 1]-48 == 1 && (pc[x][y + 1] == 0 || pc[x][y + 1] > pc[x][y]+1)) {
				push(q, x, q2);
				push(q3, y + 1, q4);
				pc[x][y + 1] = pc[x][y] + 1;
			}
		if (x > 0)
			if (p[x - 1][y]-48 == 1 && (pc[x - 1][y] == 0 || pc[x - 1][y] > pc[x][y]+1)) {
				push(q, x - 1, q2);
				push(q3, y, q4);
				pc[x - 1][y] = pc[x][y] + 1;
			}
		if (y > 0)
			if (p[x][y - 1]-48 == 1 && (pc[x][y - 1] == 0 || pc[x][y - 1] > pc[x][y]+1)) {
				push(q, x, q2);
				push(q3, y - 1, q4);
				pc[x][y - 1] = pc[x][y] + 1;
			}
	} while (q->link != NULL);
	

	return pc[a-1][b-1];
}

int main(void)
{
	init(&q);
	init(&q2);
	init(&q3);
	init(&q4);
	int a, b;
	cin >> a >> b;
	char** c;
	c = (char**)malloc(sizeof(char*)*a);
	pc = (int**)malloc(sizeof(int*)*a);
	for (int i = 0; i < a; i++) {
		c[i] = (char*)malloc(sizeof(char)*b + 1);
		pc[i] = (int*)malloc(sizeof(int)*b);
	}
	for (int i = 0; i<a; i++)
		cin >> c[i];
	for (int i = 0; i<a; i++)
		for (int j = 0; j<b; j++) 
			pc[i][j] = 0;

	cout << tra2(c, a, b);
	return 0;
}
