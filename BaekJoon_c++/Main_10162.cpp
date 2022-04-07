#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	// 분, 초로 바꾸기
	int minute = T / 60;
	int second = T % 60;

	// A B C 버튼 클릭 횟수 저장
	int A_cnt = minute / 5;

	// 5로 나눈 나머지는 1분 단위이기 때문에
	int B_cnt = minute % 5;

	int C_cnt = second / 10;
	second = second % 10;

	if (second != 0) {
		// 시간을 정확히 맞출 수 없는 경우
		cout << "-1" << endl;
	}
	else {
		cout << A_cnt << " " << B_cnt << " " << C_cnt << endl;
	}
}