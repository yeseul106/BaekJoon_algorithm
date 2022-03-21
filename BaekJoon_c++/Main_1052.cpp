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

	// 상점에서 사는 물병
	int buy_bottle = 0;
	int cnt = 0;

	while (true) {
		
		// 물병을 최대한 합쳐보기
		int remainder = 0; // 남는 물병

		// N을 2로 계속해서 나누면서 계산해야하기 때문에 tmp 써야함
		int tmp_N = N;

		while (tmp_N != 0) {

			if (tmp_N % 2 != 0) {
				remainder++; // 물병의 갯수
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