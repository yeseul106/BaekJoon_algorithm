/*
-문제: 방향 없는 그래프가 주어졌을 때, 연결 요소 (Connected Component)의 개수를 구하는 프로그램을 작성하시오.

-입력: 첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. 
(1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.

====> BFS로 풀기!!
*/

#include <iostream>
#include <queue>
#include <cstdio>
#pragma warning (disable:4996)
using namespace std;

int N, M;

void BFS(int a,  int** graph,bool* visited) {
	queue<int> Q;
	visited[a] = true; //방문했다고 표시

	Q.push(a); //큐에 정점 a를 삽입
	while (!Q.empty()) {
		int k = Q.front(); Q.pop();

		for (int i = 0; i < N; i++) {
			if (graph[k][i] == 1 && !visited[i]) {
				Q.push({ i });
				visited[i] = true;
			}
		}
	}
}

int componentF(int** graph, bool* visited) {
	int count = 0;
		for (int i = 0; i < N; i++) {
			if (!visited[i])
			{
				count++;
				BFS(i, graph, visited);
			}
		}
	return count;
}



int main() {
	cin >> N >> M;
	
	bool* visited = new bool[N]; // 배열 버전 new 연산자를 사용한다. 배열 길이는 상수가 아니여도 된다. (동적배열할당)
	int** graph = new int*[N];

	//그래프 만들기
	for (int i = 0; i < N; i++) {
		visited[i] = false;
		graph[i] = new int[N];

	}

	//그래프 초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			graph[i][j] = 0;
		}
	}

	//그래프 연결하기
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a-1][b-1] = 1;
		graph[b-1][a-1] = 1;
	}
	int result = componentF(graph,visited);
	cout << result;
}