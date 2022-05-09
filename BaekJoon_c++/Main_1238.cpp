#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int short_dist[20001];

vector<pair<int, int>> node[1000];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, M, X; // N= �л� ��, M = ���� ����, X = ���� ���� ��ȣ

	cin >> N >> M >> X;

	for (int i = 0; i < M; i++) {
		int u, v, t;
		cin >> u >> v >> t;
		node[u].push_back(make_pair(t, v));
	}

	fill(short_dist, short_dist + N + 1, INF); // ���Ѵ� ������ �ʱ�ȭ

	short_dist[X] = 0; // K��° ��尡 ��� ���

	// �켱���� ť => priority_queue<�ڷ���, ����ü, �� ������>
	// greater�� ����Ͽ� ���������� min heap�� ������.
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	// ��� ��带 pq�� �ְ� ���ͽ�Ʈ�� �˰��� ����
	pq.push(make_pair(short_dist[X], X));

	while (!pq.empty()) {
		// ����ġ�� ���� ���� ������ ����
		pair<int, int> now = pq.top();
		pq.pop();

		int dist = now.first; // ����ġ
		int idx = now.second; // ���� ���

		// �ִ� �Ÿ��� ������ ���� �湮���� ����
		if (dist > short_dist[idx]) continue;

		// idx�� ������ ����Ǿ� �ִ� ������ ��� ����
		for (int i = 0; i < node[idx].size(); i++) {
			pair<int, int> next = node[idx][i];
			int weight = next.first;
			int next_idx = next.second;

			// ���� ����Ǿ� �ִ� �ִܰŸ����� ���ο� �ִ� ��θ� ã���� ������ ����
			if (short_dist[next_idx] > dist + weight) {
				short_dist[next_idx] = dist + weight;
				pq.push(make_pair(short_dist[next_idx], next_idx));
			}
		}
	}
	
	int max_weight = -1;

	for (int i = 1; i <= N; i++) {
		if (max_weight < short_dist[i])
			max_weight = short_dist[i];
	}

	cout << max_weight << endl;
	return 0;
}