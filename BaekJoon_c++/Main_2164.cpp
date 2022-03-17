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

	// ������ ������ ���� ���ؼ��� N-1�� ����
	for (int i = 0; i < N - 1; i++) {
		// �� ���� ����
		Q.pop();

		// ���� �� �� �ڷ� ������
		int next = Q.front();
		Q.pop();
		Q.push(next);
	}

	cout << Q.front() << endl;
}