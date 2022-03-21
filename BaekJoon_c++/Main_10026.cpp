#include <iostream>
#include <string>
using namespace std;

int N;
string grid[101];
int isVisited[101][101];

int delta_x[] = { -1,1,0,0 }; 
int delta_y[] = { 0,0,-1,1 };

bool isValid(int a, int b) {
	// 탐색하려는 X 좌표값과 Y 좌표값이 범위 내에 있는지 확인
	return((a >= 0 && a < N) && (b >= 0 && b < N));
}

void normal_DFS(int a, int b) {

	for (int i = 0; i < 4; i++) {

		// 상하좌우를 탐색
		int dy = a + delta_y[i];
		int dx = b + delta_x[i];

		if (isValid(dy, dx) && // 좌표값이 유효하고,
			isVisited[dy][dx] == 0 && // 이전에 방문한 적이 없으며,
			grid[dy][dx] == grid[a][b]) { // 기준 char 값과 탐색하는 char 값이 같다면
			
			isVisited[dy][dx] = 1;
			normal_DFS(dy, dx);
		}

	}
}

void abnormal_DFS(int a, int b) {

	for (int i = 0; i < 4; i++) {
		int dy = a + delta_y[i];
		int dx = b + delta_x[i];

		if (isValid(dy, dx) && // 좌표값이 유효하고,
			isVisited[dy][dx] == 0 && // 이전에 방문한 적이 없으며,
			((grid[dy][dx] == grid[a][b]) || // 기준 char 값과 탐색하는 char 값이 같거나
				(grid[dy][dx]=='R' && grid[a][b] == 'G') || // R, G 는 같은 색으로
				(grid[dy][dx] == 'G' && grid[a][b] == 'R'))) 
		{ 

			isVisited[dy][dx] = 1;
			abnormal_DFS(dy, dx);
		}

	}
}


int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
			string tmp;
			cin >> tmp;

			grid[i] = tmp;
	}

	int normal = 0;
	int abnormal = 0;

	// 그래프 탐색 (DFS) 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (isVisited[i][j] == 0) {
				normal++;  
				isVisited[i][j] = 1;
				normal_DFS(i, j);
			}
		}
	}
	
	// isVisited 배열 초기화 해주기
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			isVisited[i][j] = 0;

		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (isVisited[i][j] == 0) {
				abnormal++; // 구역의 갯수 + 1
				isVisited[i][j] = 1;
				abnormal_DFS(i, j);
			}
		}
	}

	cout << normal <<" " << abnormal << endl;
}