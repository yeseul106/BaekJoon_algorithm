#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	// ��, �ʷ� �ٲٱ�
	int minute = T / 60;
	int second = T % 60;

	// A B C ��ư Ŭ�� Ƚ�� ����
	int A_cnt = minute / 5;

	// 5�� ���� �������� 1�� �����̱� ������
	int B_cnt = minute % 5;

	int C_cnt = second / 10;
	second = second % 10;

	if (second != 0) {
		// �ð��� ��Ȯ�� ���� �� ���� ���
		cout << "-1" << endl;
	}
	else {
		cout << A_cnt << " " << B_cnt << " " << C_cnt << endl;
	}
}