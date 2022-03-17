#include <iostream>
#include <queue>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);

	queue<int> Q;
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		Q.push(i+1);
	}

	// 마지막 한장이 남기 위해서는 N-1번 돌기
	for (int i = 0; i < N - 1; i++) {
		// 맨 윗장 제거
		Q.pop();

		// 다음 장 맨 뒤로 보내기
		int next = Q.front();
		Q.pop();
		Q.push(next);
	}

	cout << Q.front() << endl;
}