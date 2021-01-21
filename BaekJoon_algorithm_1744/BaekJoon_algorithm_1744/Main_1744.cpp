/*
-����: 

���̰� N�� ������ �־����� ��, �� ������ ���� ���Ϸ��� �Ѵ�. ������, �׳� �� ������ ���� ��� ���ؼ� ���ϴ� ���� �ƴ϶�, ������ �� ���� �������� �Ѵ�. 
� ���� �������� �� ��, ��ġ�� ������� ���� �� �ִ�. ������, ���� ��ġ�� �ִ� ��(�ڱ� �ڽ�)�� ���� ���� �Ұ����ϴ�.
�׸��� � ���� ���� �Ǹ�, ������ ���� ���� �� ���� ���� ���� ���� �Ŀ� ���Ѵ�.
���� ���, � ������ {0, 1, 2, 4, 3, 5}�� ��, �׳� �� ������ ���� ���ϸ� 0+1+2+4+3+5 = 15�̴�. ������, 2�� 3�� ����, 4�� 5�� ���� �Ǹ�, 0+1+(2*3)+(4*5) = 27�� �Ǿ� �ִ밡 �ȴ�.
������ ��� ���� �� �ѹ��� ���ų�, �ƴϸ� ���� �ʾƾ��Ѵ�.
������ �־����� ��, ������ �� ���� ������ ������ ��, �� ���� �ִ밡 �ǰ� �ϴ� ���α׷��� �ۼ��Ͻÿ�.

-�Է�:

ù° �ٿ� ������ ũ�� N�� �־�����. N�� 10,000���� ���� �ڿ����̴�. ��° �ٺ��� N���� �ٿ�, ������ �� ���� �־�����. 
������ ���� -10,000���� ũ�ų� ����, 10,000���� �۰ų� ���� �����̴�.
*/

/*

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#pragma warning (disable:4996)
using namespace std;
#define MAX_SIZE 10000

int main() {

	int minus[MAX_SIZE] = {}; //���� �迭
	int plus[MAX_SIZE] = {}; //��� �迭

	bool isZero = false;
	int countOne = 0;
	int minusEnd = -1;
	int plusEnd = -1;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;

		if (temp == 0)
			isZero = true;
		else if (temp < 0)
		{
			minusEnd++;
			minus[minusEnd] = temp;
		}
		else if (temp == 1)
			countOne++;
		else
		{
			plusEnd++;
			plus[plusEnd] = temp;
		}
	}


	//�迭 �����ϱ� (�������� ����)
	sort(minus, minus+minusEnd+1);
	sort(plus, plus+plusEnd+1, greater<int>());

	/*
	for (int i = 0; i < minusEnd + 1; i++)
		printf("%d ", minus[i]);
	printf("\n");
	for (int i = 0; i < plusEnd + 1; i++)
		printf("%d ", plus[i]);
	*/

	//���ϱ�
	int plustmp=0;
	int minustmp=0;

	for (int i = 0; i < minusEnd; i=i+2)
	{
		minustmp += minus[i] * minus[i + 1];
	}
	for (int i = 0; i < plusEnd; i=i+2) {
		plustmp += plus[i] * plus[i + 1];
	}


	if (minusEnd!=-1 && minusEnd % 2 == 0 && isZero)
		minustmp += 0;
	else if (minusEnd != -1 && minusEnd % 2 == 0 && !isZero)
		minustmp += minus[minusEnd];

	if (plusEnd!=-1 && plusEnd % 2 == 0)
		plustmp += plus[plusEnd];

	int result;
	result = plustmp + minustmp + (countOne*1);

	cout << result;
}

