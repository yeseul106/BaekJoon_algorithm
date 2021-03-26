#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int N;
	int result = 0;
	cin >> N;

	//1부터 N까지 쭉 돌아도 되지만 더 효율적으로!
	//각 자리의 최댓값은 9 => 자리수만큼 9를 더한 값을 N에서 뺀것부터 탐색을 시도해도 됨

	//N의 자릿수 구하기
	int count = 0;
	int tmp = N;

	while (tmp != 0) {
		count++;
		tmp /= 10;
	}

	//탐색 시작값 구하기
	int start = N - 9 * count;


	for (int i = start; i < N; i++) {
		int M = i;
		int temp = i;

		for (int j = 0; j < count; j++) {
			M += temp % 10;
			temp /= 10;
		}

		if (M == N) {
			result = i;
			break;
		}
	}
	
	cout << result;
}