#include <iostream>
#include <algorithm>
using namespace std;

// ���� ����Ϸ��� �ϸ� �ȵ� ,,,
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

		// answer = fac / 10.0f; ������ ����°ǰ� ,,,
		//double fac = factorial(N);
		
		// ���μ����� ���̵� ����ؼ� Ǯ����ϴ� ���� !!
		// 10 = 5 * 2 �ٵ� ���丮���̴ϱ� 5�� �ִٸ� 2�� ��������.
		// �������� ���� 5�� ��� ������ �ľ��ϸ� ��.

		for (int i = 5; i <= N; i*=5) {
			answer += N / i; // ��� ���ش� �� �ȵ�,,
		}


		cout << answer << endl;
	}

}