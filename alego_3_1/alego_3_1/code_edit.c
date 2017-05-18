#include<stdio.h>

int factorial(int N) {//���丮��
	int result = N;
	while (N > 1) {
		result = result*(--N);
	}
	return result;
}

int permu(int numberOfOder, int one, int two, int three) {//���� ���� �ִ� ����
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

int socket(int N, int one, int two, int three) {//ó���ϴ� �Լ�

	int result = 0;

	result = result + permu(N, one, two, three);//1�θ� ��������
												//1�� 2���� �ٲٸ鼭 ���
	while (one >= 2)
	{
		one -= 2;
		two++;
		N--;
		result = result + permu(N, one, two, three);
	}
	//1�� 3���� �ٲٸ鼭 ���
	while (one >= 3)
	{
		one -= 3;
		three++;
		N -= 2;
		result = result + permu(N, one, two, three);
	}

	return result;
}

int carculration(int Q, int R) {// ��Ǯ�� �Ǵ� ������ ��Ÿ�½��ϴ�.
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

		printf("N�� �Է��� �ּ���: ");
		scanf("%d", &input);
		printf("\n");

		q = input / 5;
		r = input % 5;
		
		carculration(q, r);

		printf("���: %d\n", result);

	}
	
}