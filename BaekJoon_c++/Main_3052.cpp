#include <iostream>
using namespace std;

int main() {

	int result = 0;
	int prev = -1;
	
	bool count[42] = { false };

	// 10���� ���� �Է� �ޱ�
	for (int i = 0; i < 10; i++) {
		int num;
		cin >> num;

		int idx = num % 42;
		
		if (!count[idx])
			result++;

		count[idx] = true;

	}

	cout << result;
}