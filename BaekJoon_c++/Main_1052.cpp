#include <iostream>
#include <math.h>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);

	int N, K;

	cin >> N >> K;

	if (N <= K)
	{
		cout << 0 << "\n"; return 0;
	}

	// �������� ��� ����
	int buy_bottle = 0;
	int cnt = 0;

	while (true) {
		
		// ������ �ִ��� ���ĺ���
		int remainder = 0; // ���� ����

		// N�� 2�� ����ؼ� �����鼭 ����ؾ��ϱ� ������ tmp �����
		int tmp_N = N;

		while (tmp_N != 0) {

			if (tmp_N % 2 != 0) {
				remainder++; // ������ ����
			}

			tmp_N /= 2;
		}

		if (remainder <= K)
			break;
		
		N++;
		buy_bottle++;
	}

	cout << buy_bottle << endl;
}