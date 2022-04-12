#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define INF 987654321
using namespace std;

int short_dist[20001];

//2차원 배열을 표현 => V는 최대 20000까지 주어지므로 메모리 초과가 걸린다.
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
	fill(short_dist, short_dist + V + 1, INF); // 무한대 값으로 초기화

	short_dist[K] = 0; // K번째 노드가 출발 노드

	// 우선순위 큐 => priority_queue<자료형, 구현체, 비교 연산자>
	// greater을 사용하여 내림차순인 min heap을 만들음.
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	// 출발 노드를 pq에 넣고 다익스트라 알고리즘 시작
	pq.push(make_pair(short_dist[K], K));

	while (!pq.empty()) {
		// 가중치가 가장 작은 간선을 꺼냄
		pair<int, int> now = pq.top();
		pq.pop();

		int dist = now.first; // 가중치
		int idx = now.second; // 연결 노드

		// idx번 정점과 연결되어 있는 간선을 모두 돌기
		for (int i = 0; i < node[idx].size(); i++) {
			pair<int, int> next = node[idx][i];
			int weight = next.first;
			int next_idx = next.second;

			// 현재 저장되어 있는 최단거리보다 새로운 최단 경로를 찾으면 작으면 갱신
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