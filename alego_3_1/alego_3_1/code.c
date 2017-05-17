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
	if (numberOfOder == 0)
		numberOfOder++;
	if (one == 0)
		one++;
	if (two == 0)
		two++;
	if (three == 0)
		three++;

	result = factorial(numberOfOder) / (factorial(one)*factorial(two)*factorial(three));
	return result;
}

int TwoThree(int N, int twocount, int threecount) {
	int two_=N, three_=N;
	int twoCount= twocount, threeCount = threecount;
	int result = 0;
	
	
	//������ 1�� 2�θ� �����Ȱ��
	while (two_ >= 2)
	{
		two_ = two_-2;
		twoCount++;
		result = result + permu((two_+twoCount), two_, twoCount, 1);

	}

	//������ 1�� 3���θ� �����Ȱ��
	while (three_ > 3)
	{
		three_ = three_-3;
		threeCount++;
		result = result + permu((three_+threeCount), three_, 1, threeCount);

	}

	return result;
}

int combi(int N) {// ������ 2�� 3�� �Ѵ� �ִ°��
	int combi = N;
	int twoCount=0, threeCount=0, combiCount = 0;
	int result=0;
	while (combi > 4) {
		combi = combi - 5;
		twoCount++;
		threeCount++;
		if (combi < 0)
			combi = 1;
		result = result + permu((twoCount+threeCount+combi), combi, twoCount, threeCount);
		result = result + TwoThree((combi+ twoCount+ threeCount), twoCount, threeCount);
	}
	return result;
}
void main() {
	int input;
	int result = 0;

	printf("N�� �Է��� �ּ���: ");
	scanf("%d", &input);
	
	result = TwoThree(input,0,0)+combi(input);
	result++;
	printf("/n ���: %d", result);




}