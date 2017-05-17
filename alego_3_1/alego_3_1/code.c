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
	
	
	//변수가 1과 2로만 구성된경우
	while (two_ >= 2)
	{
		two_ = two_-2;
		twoCount++;
		result = result + permu((two_+twoCount), two_, twoCount, 1);

	}

	//변수가 1과 3으로만 구성된경우
	while (three_ > 3)
	{
		three_ = three_-3;
		threeCount++;
		result = result + permu((three_+threeCount), three_, 1, threeCount);

	}

	return result;
}

int combi(int N) {// 변수가 2와 3이 둘다 있는경우
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

	printf("N을 입력해 주세요: ");
	scanf("%d", &input);
	
	result = TwoThree(input,0,0)+combi(input);
	result++;
	printf("/n 결과: %d", result);




}