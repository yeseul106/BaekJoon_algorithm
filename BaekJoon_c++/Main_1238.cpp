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

	int N, M, X; // N= 학생 수, M = 도로 개수, X = 도착 마을 번호

	cin >> N >> M >> X;

	for (int i = 0; i < M; i++) {
		int u, v, t;
		cin >> u >> v >> t;
		node[u].push_back(make_pair(t, v));
	}

	fill(short_dist, short_dist + N + 1, INF); // 무한대 값으로 초기화

	short_dist[X] = 0; // K번째 노드가 출발 노드

	// 우선순위 큐 => priority_queue<자료형, 구현체, 비교 연산자>
	// greater을 사용하여 내림차순인 min heap을 만들음.
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	// 출발 노드를 pq에 넣고 다익스트라 알고리즘 시작
	pq.push(make_pair(short_dist[X], X));

	while (!pq.empty()) {
		// 가중치가 가장 작은 간선을 꺼냄
		pair<int, int> now = pq.top();
		pq.pop();

		int dist = now.first; // 가중치
		int idx = now.second; // 연결 노드

		// 최단 거리가 정해진 곳은 방문하지 않음
		if (dist > short_dist[idx]) continue;

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
	
	int max_weight = -1;

	for (int i = 1; i <= N; i++) {
		if (max_weight < short_dist[i])
			max_weight = short_dist[i];
	}

	cout << max_weight << endl;
	return 0;
}