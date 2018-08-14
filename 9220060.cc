#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct mystack {
	int num;
	struct mystack* next;
}mystack;


void push(int x, mystack** stack) {

	mystack* node;
	node = (mystack*)malloc(sizeof(mystack));
	node->next = NULL;
	node->num = x;
	if ((*stack) == NULL) {
		*stack = node;
		return;
	}
	node->next = *stack;
	*stack = node;
}
void pop(mystack** stack) {
	if (*stack == NULL) {
		cout << "-1" << endl;
		return;
	}
	cout << (*stack)->num << endl;
	mystack* temp;
	temp = *stack;
	*stack = (*stack)->next;
	free(temp);
}
void size(mystack* stack) {
	int n = 0;
	mystack* temp;
	temp = stack;
	while (temp != NULL) {
		temp = temp->next;
		n++;
	}
	cout << n << endl;;
	free(temp);
}
void empty(mystack* stack) {
	if (stack == NULL)
		cout << "1" << endl;
	else
		cout << "0" << endl;
}
void top(mystack* stack) {
	if (stack == NULL) {
		cout << "-1" << endl;
		return;
	}
	cout << stack->num << endl;
}
int main(void) {
	int N;
	int n = 0;
	int num;
	char c[10];
	cin >> N;
	mystack** stack;
	stack = (mystack**)malloc(sizeof(mystack*));
	*stack = NULL;
	int* s;
	s = (int*)malloc(sizeof(int)*N);
	int* s2;
	s2 = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i<N; i++) {
		s[i] = 0;
		s2[i] = 0;
	}
	while (n<N) {
		cin >> c;
		switch (c[0]) {
		case 'p':
			if (c[1] == 'u') {
				cin >> num;
				s[n] = 1;
				s2[n] = num;
				break;
			}
			else {
				s[n] = 2;
				break;
			}
		case 't':
			s[n] = 3;
			break;
		case 's':
			s[n] = 4;
			break;
		case 'e':
			s[n] = 5;
			break;
		default:
			s[n] = 6;
			break;

		}

		n++;
	}
	for (int i = 0; i<N; i++) {
			switch (s[i]) {
			case 1:
				push(s2[i], stack);
				break;
			case 2:
				pop(stack);
				break;
			case 3:
				top(*stack);
				break;
			case 4:
				size(*stack);
				break;
			case 5:
				empty(*stack);
				break;
			default:
				break;
			}
	}


	return 0;
}