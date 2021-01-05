//BaekJoon_1987_ys =>BFS로 풀어보기!BFS안됨 DFS로
//(이 문제 까다로웠음! 정리 꼭 해두기!)

#include <iostream>
//#include <queue>
#include <cstdio>
#pragma warning (disable:4996)
using namespace std;

char board[21][21];
int visit[21][21];
//queue<pair<int, int>> q;
int R, C; //R이 가로, C가 세로
int result = 0;
int checkAlpha[26]; //이미 지나온 알파벳인지 확인하는 배열

//상하좌우
int rowtemp[] = { -1,1,0,0 };
int coltemp[] = { 0,0,-1,1 };

bool isValid(int a, int b) {
	if (a >= 0 && a < R && b >= 0 && b < C)
		return true;
	else
		return false;
}

/*int BFS(int a, int b) {
	int count = 1;
	int index = board[a][b] - 'A';
	checkAlpha[index] = 1;
	visit[a][b] = 1;
	q.push({ a,b });

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dy = y + rowtemp[i];
			int dx = x + coltemp[i];

			int checkindex = board[dy][dx] - 'A';
			if (isValid(dy, dx) && checkAlpha[checkindex] != 1 && visit[dy][dx] != 1) {
				count++;
				checkAlpha[checkindex] = 1;
				visit[dy][dx] = 1;
				q.push({ dy,dx });
			}
		}
	}

	return count;
}*/

/*이 문제의 주의할 점은 말을 놓을 수 있는 최대의 개수를 찾는 것이므로
모든 방향으로 가보면서 최대값을 결과변수에 저장 => 알파벳이 겹치면 안되지만 
갔던 곳은 또 가야함. 전체 모든 경로를 탐색해야하므로!
*/
void DFS(int a, int b, int cnt) {
	result = max(result, cnt);

	for (int i = 0; i < 4; i++) {
		int dy = a + rowtemp[i];
		int dx = b + coltemp[i];

		int check = board[dy][dx] - 'A';
		if (isValid(dy, dx) && checkAlpha[check] != 1) {
			checkAlpha[check] = 1;
			DFS(dy, dx, cnt+1);
			checkAlpha[check] = 0;
		}
	}
}

int main() {
	scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
		}
	}
	int index = board[0][0] - 'A';
	checkAlpha[index] = 1;
	DFS(0, 0, 1);
	printf("%d\n", result);
}