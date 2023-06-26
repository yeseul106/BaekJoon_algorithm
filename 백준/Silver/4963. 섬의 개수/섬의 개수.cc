//BaekJoon_4963_ys => DFS 이용

#include <iostream>
#include <cstdio>
#pragma warning (disable:4996)
using namespace std;

int island[50][50]; 
int visit[50][50];
int w, h;

//상하좌우 + 대각선
int rowtemp[] = { -1,-1,-1, 0, 0, 1,1,1 };
int coltemp[] = { -1, 0, 1,-1, 1,-1,0,1 };

void reset() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			visit[i][j] = 0;
		}
	}
}
bool isValid(int a, int b) {
	if (a >= 0 && a < h && b >= 0 && b < w)
		return true;
	else
		return false;
}

void DFS(int a, int b) {
	visit[a][b] = 1;

	for (int i = 0; i < 8; i++) {
		int dy = a + rowtemp[i];
		int dx = b + coltemp[i];

		if (isValid(dy, dx)&& island[dy][dx]==1 && visit[dy][dx] != 1)
			DFS(dy, dx);
	}
}

int searchDFS(int count) {
	int result = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (island[i][j] == 1 && visit[i][j]!=1)
			{
				count++;
				DFS(i, j);
			}
		}
	}
	return count;
}

int main() {
	while (true) {
		scanf("%d %d", &w, &h);
		if (w == 0 || h == 0)
			break;
		reset();

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> island[i][j];
			}
		}
		int count = 0;
		int result = searchDFS(count);

		printf("%d\n", result);
	}
	return 0;
}