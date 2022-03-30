#include <iostream>
#include <string>
#include <queue>
#define INF 100000
using namespace std;

int N;
int map[51][51];
int visit[51][51];
int dist[51][51]; // �ٲ���ϴ� ���� �ּ� ���� ����
queue<pair<int, int>> Q;


//������ ��� ����
int x_arr[4] = { 0, -1, 1, 0 };
int y_arr[4] = { -1, 0, 0, 1 };

bool isValid(int x, int y) {
	return (x >= 0 && x < N) && (y >= 0 && y < N);
}

void BFS() {

	//���� ��� �־��ֱ�
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

			// �湮���� �ʾҰ�, �̵��� �� �ִ� ��ǥ���̶��
			if (isValid(nx, ny)) {
				//visit[ny][nx] = 1;

				// �� ���̶��, �̵��ϱ� ���� dist ���� �� (�� ���� ������ ����)
				if (map[ny][nx] == 1 && dist[y][x] < dist[ny][nx]) {
					dist[ny][nx] = dist[y][x];
					Q.push({ nx, ny });
				}

				// ���� ���̶��, �̵��ϱ� ���� dist + 1 ���� ��
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

	// �Է� �ޱ�
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < N; j++) {
			int tmp = (s[j] - '0');
			map[i][j] = tmp;
		}
	}

	// dist �迭�� INF ������ �ʱ�ȭ
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = INF;
			visit[i][j] = 0;
		}
	}

	// visit �迭�� 0���� �ʱ�ȭ
	//memset(visit, 0, sizeof(int) * N);

	// �׷��� Ž�� - BFS Ž��
	BFS();


	cout << "BFS Ž�� ���" << endl;
	// dist �迭�� INF ������ �ʱ�ȭ
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << dist[i][j];
		}
		cout << endl;
	}

	cout << dist[N - 1][N - 1] << endl;



}