#include <iostream>
#include <algorithm>
using namespace std;

// 직접 계산하려고 하면 안됨 ,,,
//double factorial(int num) {
//	double result=1;
//	for (int i = 1; i <= num; i++) {
//		result *= i;
//	}
//	cout << "factorial result: " << result << endl;
//	return result;
//}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		long long answer = 0;
		int N;
		cin >> N;

		// answer = fac / 10.0f; 범위를 벗어나는건가 ,,,
		//double fac = factorial(N);
		
		// 소인수분해 아이디어를 사용해서 풀어야하는 문제 !!
		// 10 = 5 * 2 근데 팩토리얼이니까 5가 있다면 2는 무조건임.
		// 곱해지는 수에 5가 몇번 들어가는지 파악하면 됨.

		for (int i = 5; i <= N; i*=5) {
			answer += N / i; // 사실 이해는 잘 안됨,,
		}


		cout << answer << endl;
	}

}