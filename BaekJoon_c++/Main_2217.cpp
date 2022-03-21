#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	vector<int> rope_arr;

	int N;

	cin >> N;

	// 로프 정보 입력받기
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		rope_arr.push_back(tmp);
	}

	// 로프 정렬하기
	sort(rope_arr.begin(), rope_arr.end());
	int result = 0;

	for (int i = 0; i < N; i++) {

		// i번째 로프 값이 최소인 리스트의 길이
		int rope_cnt = N - i; 
		
		result = max(result, rope_arr[i] * rope_cnt);
		
	}

	cout << result << endl;


}