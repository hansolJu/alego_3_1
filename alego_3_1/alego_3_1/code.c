#include<stdio.h>

int factorial(int N) {//���丮��
	int result = N;
	while (N == 1) {
		result = result*(--N);
	}
	return result;
}
int permu(int numberOfOder, int one, int two, int three) {//���� ���� �ִ� ����
	int result = 0;
	result = factorial(numberOfOder) / (factorial(one)*factorial(two)*factorial(three));
}
