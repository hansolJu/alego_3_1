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
	int two_ = N, three_ = N;
	int twoCount = twocount, threeCount = threecount;
	int result = 0;


	//변수가 1과 2로만 구성된경우
	while (two_ >= 2)
	{
		two_ = two_ - 2;
		twoCount++;
		result = result + permu((two_ + twoCount), two_, twoCount, 1);

	}

	//변수가 1과 3으로만 구성된경우
	while (three_ > 3)
	{
		three_ = three_ - 3;
		threeCount++;
		result = result + permu((three_ + threeCount), three_, 1, threeCount);

	}

	return result;
}


void main() {
	int input;
	int result = 1;
	int q, r;
	while (1) {

		printf("N을 입력해 주세요: ");
		scanf("%d", &input);
		q = input / 5;
		r = input % 5;
		printf("\n");
		switch (r)
		{
		case 0: 
			result= result+ TwoThree(input,0,0) + permu((q*2), 0, q, q); // 2 3 | 0
		case 1:
			result = result + TwoThree(input, 0, 0) + permu(((q*2)+1),1,q,q); //2 3 | 1
		case 2:
			result = result+ TwoThree(input, 0, 0) + permu((q*2)+2,2,q,q)+ permu((q*2)+1,0,q+1,q) ;// 2 3 | 11 + 2 3 | 2
		case 3:
			result = result + TwoThree(input, 0, 0) + permu((q * 2) + 3, 3, q, q) + permu((q * 2) + 2, 1, q+1, q)+ permu((q * 2) + 1, 0, q, q+1);// 2 3 | 111, 21 , 3
		case 4:
			result = result + TwoThree(input, 0, 0) + permu((q * 2) + 4, 4, q, q) + permu((q * 2) + 2, 0, q + 2, q) + permu((q * 2) + 2, 1, q, q + 1);;// 2 3 | 1111, 22, 31
		default:
			break;
		}

		printf("결과: %d", result);

	}
	
}