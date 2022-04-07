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

	// 이항 계수 구하기
	int N, K;

	cin >> N >> K;

	if ( K < 0 || K > N ) { // 사실 이건 문제 조건에 제시되어 있어서 안해줘도 됨.
		cout << "0" << endl;
	}
	else {
		cout << factorial(N) / (factorial(K) * factorial(N - K)) << endl;
	}

	
}