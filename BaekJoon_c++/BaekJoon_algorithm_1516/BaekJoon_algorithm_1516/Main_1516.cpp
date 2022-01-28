#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N;
int indegree[501];
int weight[501];
int dp[501];

vector<int> v[501];
queue<int> q;
queue<int> answer;

int main() {
	ios_base::sync_with_stdio(0);
	
	cin >> N;
	memset(indegree, 0, sizeof(indegree));
	memset(weight, 0, sizeof(weight));
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= N; i++) {
		cin >> weight[i];

		while (true) {
			int tmp;
			cin >> tmp;
			if (tmp == -1)
				break;
			v[tmp].push_back(i);
			indegree[i]++;
		}
	}


	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) {
			q.push(i);
			dp[i] = weight[i]; // ������ �Ǽ��ؾ��ϴ� �ǹ��� ���� ���̹Ƿ� ����
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < v[x].size(); i++) {
			int num = v[x].at(i);
			// �� �����ɸ��� �ð��� �����ؾ��ϹǷ� ������ �ð��̶� ���� ��η� ���� �ð��� ��
			dp[num] = max(dp[num], dp[x] + weight[num]);
			indegree[num]--;

			if (indegree[num] == 0) {
				q.push(num);
			}
		} 
	}

	for (int i = 1; i <= N; i++) {
		cout << dp[i] << endl;
	}
}