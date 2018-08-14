#include <iostream>
#include <stdlib.h>
using namespace std;
int main(void)
{
	int n;
	cin >> n;
	int* score;
	score = (int*)malloc(sizeof(int)*n);
	char* quiz;
	quiz = (char*)malloc(sizeof(char) * 80);
	int num = 0;
	while (num<n) {
		for (int i = 0; i < 80; i++)
			quiz[i] = 'Z';
		int tmp = 0;
		int s = 0;
		int s2 = 0;
		cin >> quiz;

		while (quiz[tmp] != 'Z' && tmp < 80) {
			if (quiz[tmp] == 'O') {
				s2++;
				s = s + s2;
			}
			else if (quiz[tmp] == 'X')
				s2 = 0;
			tmp++;
		}
		score[num] = s;
		num++;	
	}
	for (int i = 0; i < n; i++)
		cout << score[i] << endl;
	
	return 0;
}