#include<stdio.h>

unsigned __int64 factorial(unsigned __int64 N) {//팩토리얼
	unsigned __int64 result = N;
	while (N > 1)
	{
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

int socket(int n, int one, int two, int three) {//처리하는 함수

	int result = 0;
	int One = one;
	int N = n;
	int Two = two;
	int Three = three;

	result = result + permu(N, one, two, three);//1로만 되있을때

	//1을 2으로 바꾸면서 계산
	while (one >= 2)
	{
		one -= 2;
		two++;
		n--;
		result = result + permu(n, one, two, three);
	}
	//1을 3으로 바꾸면서 계산
	while (One >= 3)
	{
		One -= 3;
		Three++;
		N -= 2;
		result = result + permu(N, One, Two, Three);
	}

	return result;
}

int carculration(int Q, int R) {// 되풀이 되는 과정을 나타냈습니다.
	int result = 0;
	while (Q >= 0)
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

		result = carculration(q, r);

		printf("결과: %d\n", result);

	}

}