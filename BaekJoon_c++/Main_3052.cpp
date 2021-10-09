#include <iostream>
using namespace std;

int main() {

	int result = 0;
	int prev = -1;
	
	bool count[42] = { false };

	// 10개의 수를 입력 받기
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