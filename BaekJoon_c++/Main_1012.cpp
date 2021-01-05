//BaekJoon_1012_ys => DFS 이용해서 풀기

#include <iostream>
#include <cstdio>
using namespace std;

int map[50][50]; //배추밭 지도
int visit[50][50]; //방문했는지 기록
int m, n, k; //m은 가로, n은 세로

//상하좌우
int rowtemp[] = { -1,1,0,0 };
int coltemp[] = { 0,0,-1,1 };

void reset() {
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			map[i][j] = 0;
			visit[i][j] = 0;
		}
	}
}

bool isValid(int a, int b) {
	if (a >= 0 && a < m && b >= 0 && b < n)
		return true;
	else
		return false;
}

void dfs(int a, int b) {
	visit[a][b] = 1;
	for (int i = 0; i < 4; i++) {
		int dy = a + rowtemp[i];
		int dx = b + coltemp[i];

		if (isValid(dx, dy) && map[dy][dx] == 1 && visit[dy][dx]!=1)
			dfs(dy, dx);
	}
}

int searchDFS(int count) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && visit[i][j] != 1)
			{
				count++;
				dfs(i, j);
			}
		}
	}
	return count;
}
int main() {
	int total;
	cin >> total;


	for (int i = 0; i < total; i++) {
		cin >> m >> n >> k;

		for (int j = 0; j < k; j++) {
			int x, y;
			cin >> x >> y;
			map[y][x] = 1;
		}

		cout << searchDFS(0) << endl;
		reset();
	}

	return 0;
}