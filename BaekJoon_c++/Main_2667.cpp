#include <iostream>
#include <cstdio>
#include <algorithm>
#pragma warning (disable:4996)
using namespace std;

int m[25][25]; //주어지는 전체 배열
bool map[25][25] = { false, }; //방문했는지 안했는지
bool mapcheck[25][25] = { false, };
int house[313]; //단지에 속하는 집의 수
int n;
int cnt = 1;
int index = 0;
int total = 0;

int deltax[] = { -1,1,0,0 };
int deltay[] = { 0,0,-1,1 };

bool isValid(int a, int b) {
	return((a >= 0 && a < n) && (b >= 0 && b < n));
}

void dfs(int a, int b, int label) {
	m[a][b] = label;
	map[a][b] = true;

	for (int i = 0; i < 4; i++) {
		int dy = a + deltax[i];
		int dx = b + deltay[i];

		if (m[dy][dx] == 1 && map[dy][dx] == false && isValid(dy, dx))
			dfs(dy, dx, label);
	}
}

void check(int a, int b) {
	mapcheck[a][b] = true;

	for (int i = 0; i < 4; i++) {
		int dy = a + deltax[i];
		int dx = b + deltay[i];

		if (m[dy][dx] == 1 && mapcheck[dy][dx] == false && isValid(dy, dx))
		{
			cnt++;
			check(dy, dx);
		}
	}
}

void NumberingHouse(int n) {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (m[i][j] == 1) {
				cnt = 1;
				check(i, j);
				house[index++] = cnt;
				total++;
				dfs(i, j, cnt);
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &m[i][j]);
		}
	}

	NumberingHouse(n);

	sort(house, house + index);

	cout << total << endl;
	for (int i = 0; i < index; i++)
		cout << house[i] << endl;

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << m[i][j] << " ";
		cout << "\n";
	}*/
	return 0;
}
