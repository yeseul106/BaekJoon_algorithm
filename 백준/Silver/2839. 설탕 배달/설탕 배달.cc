#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	int copyN;
	int result = 0;

	cin >> N;

	int quotient;
	int remainder;

	// 1.먼저 5로 나눠보기
	quotient = N / 5;
	remainder = N % 5;


	if (quotient > 0) { // 5로 나눠지는 수
		while (quotient >= 0) {

			result = quotient;

			if (remainder % 3 == 0) {
				result += remainder / 3;
				remainder = remainder % 3;
				cout << result << endl;
				break;
			}
			else {
				quotient--;
				remainder += 5;
			}
		}

		if (remainder != 0) {
			cout << "-1" << endl;
		}
	}
	else { // 5로 나눠지지 않는 수 => 3으로 나누기
		quotient = remainder / 3;
		remainder = remainder % 3;

		if (remainder == 0) {
			cout << quotient << endl;
		}
		else {
			cout << "-1" << endl;
		}
	}
}