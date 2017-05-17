#include<stdio.h>

int factorial(int N) {//팩토리얼
	int result = N;
	while (N == 1) {
		result = result*(--N);
	}
	return result;
}
int permu(int numberOfOder, int one, int two, int three) {//같은 것이 있는 순열
	int result = 0;
	result = factorial(numberOfOder) / (factorial(one)*factorial(two)*factorial(three));
}
