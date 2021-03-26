#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int N;
	int result = 0;
	cin >> N;

	//1���� N���� �� ���Ƶ� ������ �� ȿ��������!
	//�� �ڸ��� �ִ��� 9 => �ڸ�����ŭ 9�� ���� ���� N���� ���ͺ��� Ž���� �õ��ص� ��

	//N�� �ڸ��� ���ϱ�
	int count = 0;
	int tmp = N;

	while (tmp != 0) {
		count++;
		tmp /= 10;
	}

	//Ž�� ���۰� ���ϱ�
	int start = N - 9 * count;


	for (int i = start; i < N; i++) {
		int M = i;
		int temp = i;

		for (int j = 0; j < count; j++) {
			M += temp % 10;
			temp /= 10;
		}

		if (M == N) {
			result = i;
			break;
		}
	}
	
	cout << result;
}