#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> vec;
	long result = 0;

	// 입력 받기
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;

		vec.push_back(tmp);
	}

	// next_permutation으로 조합 구하기 ==> 시간 초과 !!
	//vector<int> temp;
	//temp.push_back(1);
	//temp.push_back(1);

	//for (int i = 0; i < N-2; i++) {
	//	temp.push_back(0);
	//}


	//do {
	//	int num = 1;
	//	for (int i = 0; i < vec.size(); ++i) {
	//		if (temp[i] == 1)
	//			num *= vec[i];
	//	}
	//	//cout << "num: " << num << endl;
	//	result += num;
	//} while (prev_permutation(temp.begin(), temp.end()));

	// 구간 합으로 구하기
	//(1*2) + (1*3) + (1*4) + (2*3) + (2*4) + (3*4)
	//(1*(2+3+4)) + (2*(3+4)) + (3*4)

	long psum[100000];

	psum[0] = vec[0];

	for (int i = 1; i < N; ++i) {
		psum[i] = psum[i - 1] + vec[i];
	}

	for (int i = 0; i < N - 1; ++i) {
		result += vec[i] * (psum[N - 1] - psum[i]);
	}

	cout << result << endl;
 }