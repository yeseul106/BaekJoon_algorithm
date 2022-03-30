#include <iostream>
#include <string>
#include <queue>
#define INF 100000
using namespace std;

int N;
int map[51][51];
int visit[51][51];
int dist[51][51]; // 바꿔야하는 방의 최소 개수 저장
queue<pair<int, int>> Q;


//인접한 노드 접근
int x_arr[4] = { 0, -1, 1, 0 };
int y_arr[4] = { -1, 0, 0, 1 };

bool isValid(int x, int y) {
	return (x >= 0 && x < N) && (y >= 0 && y < N);
}

void BFS() {

	//시작 노드 넣어주기
	Q.push({ 0, 0 });
	dist[0][0] = 0;

	while (!Q.empty()) {
		pair<int, int> now = Q.front();
		Q.pop();

		int x = now.first;
		int y = now.second;

		for (int i = 0; i < 4; i++) {
			int nx = x + x_arr[i];
			int ny = y + y_arr[i];

			// 방문하지 않았고, 이동할 수 있는 좌표점이라면
			if (isValid(nx, ny)) {
				//visit[ny][nx] = 1;

				// 흰 방이라면, 이동하기 전의 dist 값과 비교 (더 작은 값으로 갱신)
				if (map[ny][nx] == 1 && dist[y][x] < dist[ny][nx]) {
					dist[ny][nx] = dist[y][x];
					Q.push({ nx, ny });
				}

				// 검은 방이라면, 이동하기 전의 dist + 1 값과 비교
				if (map[ny][nx] == 0 && dist[y][x] + 1 < dist[ny][nx]) {
					dist[ny][nx] = dist[y][x] + 1;
					Q.push({ nx, ny });
				}


			}
		}
	}

}


int main() {

	ios_base::sync_with_stdio(0);

	cin >> N;

	// 입력 받기
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < N; j++) {
			int tmp = (s[j] - '0');
			map[i][j] = tmp;
		}
	}

	// dist 배열은 INF 값으로 초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = INF;
			visit[i][j] = 0;
		}
	}

	// visit 배열은 0으로 초기화
	//memset(visit, 0, sizeof(int) * N);

	// 그래프 탐색 - BFS 탐색
	BFS();


	cout << "BFS 탐색 결과" << endl;
	// dist 배열은 INF 값으로 초기화
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << dist[i][j];
		}
		cout << endl;
	}

	cout << dist[N - 1][N - 1] << endl;



}