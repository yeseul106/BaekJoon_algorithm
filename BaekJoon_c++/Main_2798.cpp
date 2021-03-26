//내가 실수한 부분들
// 1) 내림차순으로 정렬한 다음 앞부터 차례대로 탐색해도 차이를 비교해야함
// EX --- 10 8 4 2 1 , M이 14일 때, 정답은 14(8+4+2)인데 나의 코드는 13(10+2+1)을 고르게 된다.

// 2) 반드시 3장을 뽑아야 하는 것을 고려하지 못함.



#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#pragma warning (disable:4996)
using namespace std;

int main() {
	vector<int> arr;

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int k;
		cin >> k;
		arr.push_back(k);
	}

	int result=300000;

	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			for (int k = j + 1; k < N; k++) {
				int temp = arr[i] + arr[j] + arr[k];

				if (temp < M) {
					if (abs(result-M) >= abs(temp-M))
					{
						result = temp;
					}
				}
				else if (temp == M)
				{
					result = temp;
					i = N-1;
				}
			}
		}
	}
	cout << result;
} 