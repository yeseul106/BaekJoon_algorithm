#include <iostream>
#include <queue>
using namespace std;

int main() {

	int score[101];

	int test;
	cin >> test; // �׽�Ʈ���̽� ����

	for (int i = 0; i < test; i++) {
		queue<pair<int, int>> Q;
		int n, m;
		int count = 0;
		cin >> n >> m; // n: ������ ����, m: �ñ��� ������ ��ġ
		cout << "n: " << n << " m: " << m << endl;

		for (int j = 0; j < n; j++) {
			int tmp;
			pair<int, int> document;
			cin >> tmp;
			document = pair<int, int>(j, tmp);

			score[j] = tmp;
			Q.push(document); //ť�� ����ֱ�
		}

		// ť ���鼭 �����ϱ�
		for (int k = 0; k < Q.size(); k++) {
			int num = Q.front().second; // ���� ť�� ù���� ����

			for (int check = k + 1; check < Q.size(); check++) {
				if (num < score[check]) { // ť�� �� �� ���Һ��� �� ū ������ ���� ��
					pair<int, int> temp = Q.front();
					Q.pop(); //���� ���� ����
					Q.push(temp);
					break;
				}
			}
		}

		for (int k = 0; k < Q.size(); k++) {
			pair<int,int> num = Q.front();
			count++;
			if (num.first == m) {
				cout << count << endl;
				break;
			}
		}

	}

}