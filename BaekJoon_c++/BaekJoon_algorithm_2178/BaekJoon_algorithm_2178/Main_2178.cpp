/* 
- 문제

N×M크기의 배열로 표현되는 미로가 있다.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 
한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

- 입력:
첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

- 출력:
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.
*/

#include <iostream>
#include <queue>
using namespace std;

int main() {
	int N, M;
	int map[100][100];
	int visit[100][100] = { 0 };
	queue<pair<int, int>> Q;

	cin >> N >> M;

	// 미로 입력 받기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp;
			cin >> tmp;

			map[i][j] = tmp;
		}
	}

	// 미로 탐색 하기 (BFS - 옆으로 가면서 아래로 내려가며 탐색하기)
	// 기존 BFS 문제들 처럼 상하좌우를 탐색해야할듯..
	int count = 0;

	count++;
	Q.push(new pair<int, int>(0, 0));
	visit[0][0] = 1;


	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
			if (map[r][c] == 1 && visit[r][c] == 0) {
				Q.push(new pair<int, int>(r, c));
				visit[r][c] == 1;
			}
			while (!Q.empty()) {
				pair<int, int> now = Q.front();
				Q.pop();

			}
		}
	}



}