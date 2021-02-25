//DFS 문제풀기
//문제: 신종 바이러스인 웜 바이러스는 네트워크를 통해 전파된다.한 컴퓨터가 웜 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서 연결되어 있는 모든 컴퓨터는 웜 바이러스에 걸리게 된다.
//
//입력: 첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다. 둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 
//      이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.
//출력: 1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.

#include <iostream>
#include <cstdio>
using namespace std;

int visit[100];
int graph[100][100];
int computer;
int cnt;

void DFS(int a) {
	visit[a] = 1;

	for (int i = 0; i < computer; i++) {
		if (visit[i] != 1 && graph[a][i] == 1)
		{
			cnt++;
			DFS(i);
		}
	}
}

int main() {
	cin >> computer;

	int network;
	cin >> network;

	//그래프 초기화 하기
	for (int i = 0; i < computer; i++) {
		visit[i] = 0;
		for (int j = 0; j < computer; j++) {
			graph[i][j] = 0;
		}
	}

	//그래프 연결하기
	for (int i = 0; i < network; i++) {
		int a, b;
		cin >> a >> b;
		graph[a - 1][b - 1] = 1;
		graph[b - 1][a - 1] = 1;
	}
	cnt = 0;

	DFS(0);
	cout << cnt;

	return 0;
}