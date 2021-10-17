#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//ť ����غ���
void showAll(queue<pair<int,int>> q)
{
	cout << "ť ����-------------------------" << endl;
	while (!q.empty())
	{
		cout << "inx: " << q.front().first << ' ';
		cout << "value: " << q.front().second << ' ';
		cout << endl;
		q.pop();
	}
	cout << "-------------------------------------" << endl;
}

int main() {
	
	int test;
	cin >> test; // �׽�Ʈ���̽� ����

	for (int i = 0; i < test; i++) {
		queue<pair<int, int>> Q;
		queue<pair<int, int>> newQ;
		vector<int> score;

		int n, m;
		int count = 0;
		cin >> n >> m; // n: ������ ����, m: �ñ��� ������ ��ġ
		//cout << "n: " << n << " m: " << m << endl;

		for (int j = 0; j < n; j++) {
			int tmp;
			pair<int, int> document;
			cin >> tmp;
			document = pair<int, int>(j, tmp);

			score.push_back(tmp);
			Q.push(document); //ť�� ����ֱ�
		}
		
		int idx = 0;
		// ť ���鼭 �����ϱ�
		while(!Q.empty()) {
			int num = Q.front().second; // ���� ť�� ù��° ����
			bool change = false;

			for (int check = 1; check < Q.size(); check++) {

				if (num < score[check]) { // ť�� �� �� ���Һ��� �� ū ������ ���� ��
					pair<int, int> temp = Q.front();
					Q.pop(); //���� ���� ����
					Q.push(temp);

					//������ ���� �ٲ��ֱ�
					score.erase(score.begin() + 0);
					score.push_back(num);
					change = true;
					break;
				}
			}
			if (!change) {  //�� �̻� �ٲ� ���� ����
				newQ.push(Q.front());
				Q.pop();
				score.erase(score.begin() + 0);
			}
		}

		//ť ���� Ȯ��
		//showAll(newQ);

		while(!newQ.empty()) {
			pair<int,int> result = newQ.front();
			count++;
			if (result.first == m) {
				cout << count << endl;
				break;
			}
			newQ.pop();
		}

	}

}