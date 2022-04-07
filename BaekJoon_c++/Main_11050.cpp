#include <iostream>
using namespace std;

int factorial(int num) {
	int result = 1;
	for (int i = 0; i < num; i++) {
		result *= (num - i);
	}

	return result;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	// ���� ��� ���ϱ�
	int N, K;

	cin >> N >> K;

	if ( K < 0 || K > N ) { // ��� �̰� ���� ���ǿ� ���õǾ� �־ �����൵ ��.
		cout << "0" << endl;
	}
	else {
		cout << factorial(N) / (factorial(K) * factorial(N - K)) << endl;
	}

	
}