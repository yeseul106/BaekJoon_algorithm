#include <iostream>
#include <cstdio>
#pragma warning (disable:4996)
using namespace std;

int map[50][50];
int wall[50][50];
int result;

//네 방향 모두 청소가 이미 되어있거나 벽인 경우를 체크
bool check(int r, int c) {
	if (map[r][c + 1] == 1 && map[r][c - 1] == 1 && map[r - 1][c] == 1 && map[r + 1][c] == 1)
		return true;
	else
		return false;
}

void clean_function(int r, int c, int d, int cnt, bool one) {

	//d는 방향: 0 북, 1 동, 2 남, 3 서
	if (one) {
		map[r][c] = 1;
		cnt++;
	}

	if (d == 0) {
		if (!check(r, c) && map[r][c - 1] == 0) {
			clean_function(r, c - 1, 3, cnt, true);
		}
		else if (!check(r, c) && map[r][c - 1] == 1) {
			clean_function(r, c, 3, cnt, false);
		}
		else if (check(r, c) &&  wall[r+1][c]==0) {
			clean_function(r + 1, c, 0, cnt, false);
		}
		else if (check(r, c) && wall[r+1][c]==1) {
			result = cnt;
		}
	}
	else if (d == 1) {
		if (!check(r, c) && map[r - 1][c] == 0) {
			clean_function(r - 1, c, 0, cnt, true);
		}
		else if (!check(r, c) && map[r - 1][c] == 1) {
			clean_function(r, c, 0, cnt, false);
		}
		else if (check(r, c) && wall[r][c - 1] == 0) {
			clean_function(r, c - 1, 1, cnt, false);
		}
		else if (check(r, c) && wall[r][c - 1] == 1) {
			result = cnt;
		}
	}
	else if (d == 2) {
		if (!check(r, c) && map[r][c + 1] == 0) {
			clean_function(r, c + 1, 1, cnt, true);
		}
		else if (!check(r, c) && map[r][c + 1] == 1) {
			clean_function(r, c, 1, cnt, false);
		}
		else if (check(r, c) && wall[r - 1][c] == 0) {
			clean_function(r - 1, c, 2, cnt, false);
		}
		else if (check(r, c) && wall[r - 1][c] == 1) {
			result = cnt;
		}
	}
	else if (d == 3) {
		if (!check(r, c) && map[r + 1][c] == 0) {
			clean_function(r + 1, c, 2, cnt, true);
		}
		else if (!check(r, c) && map[r + 1][c] == 1) {
			clean_function(r, c, 2, cnt, false);
		}
		else if (check(r, c) && wall[r][c + 1] == 0) {
			clean_function(r, c + 1, 3, cnt, false);
		}
		else if (check(r, c) && wall[r][c + 1] == 1) {
			result = cnt;
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	int r, c, d;
	cin >> r >> c >> d;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 1) {
				wall[i][j]= 1;
			}
		}
	}
	result = 0;

	clean_function(r, c, d,0,true);
	cout << result;
	
}