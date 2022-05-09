#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int R, C;
	char map[12][12]; // 지도로 출력되지 않는 곳도 탐색해봐야함.
	cin >> R >> C;

	// 지도 초기화
	for (int r = 0; r < R+2; r++) {
		for (int c = 0; c < C+2; c++) {
			map[r][c] = '.';
		}
	}

	// 지도 입력 받기 ( 시작하는 인덱스 주의 ! )
	for (int r = 1; r < R + 1; r++) {
		for (int c = 1; c < C + 1; c++) {
			char ch;
			cin >> ch;

			map[r][c] = ch;
		}
	}

	// 지도 복사
	char newmap[12][12];
	for (int r = 0; r < R + 2; r++) {
		for (int c = 0; c < C + 2; c++)
			newmap[r][c] = map[r][c];
	}

	// 지도 탐색하기
	for (int r = 1; r < R + 1; r++) {
		for (int c = 1; c < C + 1; c++) {
			int count = 0; // 인접한 면 중 바다를 세기

			if (map[r][c] == 'X') {
				if (map[r - 1][c] == '.') // 상
					count++;
				if (map[r][c- 1] == '.') // 좌
					count++;
				if (map[r + 1][c] == '.') // 하
					count++;
				if (map[r][c + 1] == '.') // 우
					count++;
				if (count >= 3)
					newmap[r][c] = '.';
			}
		}
	}

	// 최소 지도 범위 구하기
	int startr = R + 1;
	int lastr = 0;
	int startc = C + 1;
	int lastc = 0;

	for (int r = 0; r < R + 2; r++) {
		for (int c = 0; c < C + 2; c++) {
			if (newmap[r][c] == 'X') {
				startr = (r < startr) ? r : startr;
				startc = (c < startc) ? c : startc;
				lastr = (r > lastr) ? r: lastr;
				lastc = (c > lastc) ? c : lastc;
			}
		}
	}
	

	for (int r = startr; r <= lastr; r++) {
		for (int c = startc; c <= lastc; c++)
			cout << newmap[r][c];
		cout << endl;
	}
	



}