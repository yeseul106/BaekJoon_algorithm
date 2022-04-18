#include <iostream>
#include <vector>
using namespace std;

int combinationArr[31];
int N, M;
int cnt;

void printArray() {
	for (int i = 0; i < N; i++) {
		cout << " " << combinationArr[i];
	}
	cout << endl;
}

void combination(int n, int m, int depth, int next) {
	if (depth == n) {
		cnt++;
		//printArray();
		//cout << "cnt: " << cnt << endl;
		return;
	}

	for (int i = next; i <= m; i++) {
		combinationArr[depth] = i;
		combination(n, m, depth + 1, i + 1);
	}

	//cout << cnt << endl;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		N, M = 0;
		cnt = 0;
		cin >> N >> M;

		// M�� �߿��� N���� �̴µ�, 
		// �ٸ��� ������ �Ǹ� �ȵǹǷ� ������������ �̱� => ����

		combination(N, M, 0, 1);

		cout << cnt << endl;
	}

}