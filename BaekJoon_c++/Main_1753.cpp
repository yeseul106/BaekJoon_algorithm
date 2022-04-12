#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int short_dist[20001];

//2���� �迭�� ǥ�� => V�� �ִ� 20000���� �־����Ƿ� �޸� �ʰ��� �ɸ���.
vector<pair<int, int>> node[20001];


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int V, E, K;
	cin >> V >> E >> K;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		node[u].push_back(make_pair(w, v));
	}
	fill(short_dist, short_dist + V + 1, INF); // ���Ѵ� ������ �ʱ�ȭ

	short_dist[K] = 0; // K��° ��尡 ��� ���

	// �켱���� ť => priority_queue<�ڷ���, ����ü, �� ������>
	// greater�� ����Ͽ� ���������� min heap�� ������.
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	// ��� ��带 pq�� �ְ� ���ͽ�Ʈ�� �˰��� ����
	pq.push(make_pair(short_dist[K], K));

	while (!pq.empty()) {
		// ����ġ�� ���� ���� ������ ����
		pair<int, int> now = pq.top();
		pq.pop();

		int dist = now.first; // ����ġ
		int idx = now.second; // ���� ���

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
	for (int i = 1; i <= V; i++) {
		if (short_dist[i] == INF)
			cout << "INF\n";
		else
			cout << short_dist[i] << "\n";
	}

	return 0;
}