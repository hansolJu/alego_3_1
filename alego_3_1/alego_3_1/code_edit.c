#include<stdio.h>

int factorial(int N) {//팩토리얼
	int result = N;
	while (N > 1) {
		result = result*(--N);
	}
	return result;
}

int permu(int numberOfOder, int one, int two, int three) {//같은 것이 있는 순열
	int result = 0;

	if (one == 0)
		one++;
	if (two == 0)
		two++;
	if (three == 0)
		three++;

	result = factorial(numberOfOder) / (factorial(one)*factorial(two)*factorial(three));

	return result;
}

int socket(int N, int one, int two, int three) {//처리하는 함수

	int result = 0;

	result = result + permu(N, one, two, three);//1로만 되있을때
												//1을 2으로 바꾸면서 계산
	while (one >= 2)
	{
		one -= 2;
		two++;
		N--;
		result = result + permu(N, one, two, three);
	}
	//1을 3으로 바꾸면서 계산
	while (one >= 3)
	{
		one -= 3;
		three++;
		N -= 2;
		result = result + permu(N, one, two, three);
	}

	return result;
}

int carculration(int Q, int R) {// 되풀이 되는 과정을 나타냈습니다.
	int result = 0;
	while (Q > 0)
	{
		result = result + socket((Q * 2) + R, R, Q, Q);
		Q--;
		R += 5;
	}
	return result;
}


void main() {

	while (1) {
		int input = 0;
		int result = 0;
		int q = 0, r = 0;

		printf("N을 입력해 주세요: ");
		scanf("%d", &input);
		printf("\n");

		q = input / 5;
		r = input % 5;
		
		carculration(q, r);

		printf("결과: %d\n", result);

	}
	
}