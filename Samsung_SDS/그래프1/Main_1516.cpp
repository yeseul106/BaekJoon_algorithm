// 위상정렬
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
			dp[i] = weight[i]; // 이전에 건설해야하는 건물이 없는 것이므로 저장
		}
	}

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		for (int i = 0; i < v[x].size(); i++) {
			int num = v[x].at(i);
			// 더 오래걸리는 시간을 저장해야하므로 누적된 시간이랑 현재 경로로 지은 시간을 비교
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
