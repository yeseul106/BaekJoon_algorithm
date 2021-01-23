/*
-����: ���� ���� �׷����� �־����� ��, ���� ��� (Connected Component)�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

-�Է�: ù° �ٿ� ������ ���� N�� ������ ���� M�� �־�����. (1 �� N �� 1,000, 0 �� M �� N��(N-1)/2) ��° �ٺ��� M���� �ٿ� ������ �� ���� u�� v�� �־�����. 
(1 �� u, v �� N, u �� v) ���� ������ �� ���� �־�����.

====> BFS�� Ǯ��!!
*/

#include <iostream>
#include <queue>
#include <cstdio>
#pragma warning (disable:4996)
using namespace std;

int N, M;

void BFS(int a,  int** graph,bool* visited) {
	queue<int> Q;
	visited[a] = true; //�湮�ߴٰ� ǥ��

	Q.push(a); //ť�� ���� a�� ����
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
	
	bool* visited = new bool[N]; // �迭 ���� new �����ڸ� ����Ѵ�. �迭 ���̴� ����� �ƴϿ��� �ȴ�. (�����迭�Ҵ�)
	int** graph = new int*[N];

	//�׷��� �����
	for (int i = 0; i < N; i++) {
		visited[i] = false;
		graph[i] = new int[N];

	}

	//�׷��� �ʱ�ȭ
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			graph[i][j] = 0;
		}
	}

	//�׷��� �����ϱ�
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a-1][b-1] = 1;
		graph[b-1][a-1] = 1;
	}
	int result = componentF(graph,visited);
	cout << result;
}