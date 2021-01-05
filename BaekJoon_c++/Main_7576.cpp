//BaekJoon_7576_ys

#include <iostream>
#include <cstdio>
#include <queue>
#pragma warning (disable:4996)
using namespace std;

int m, n; //����, ����
int day; //��¥
queue<pair<int, int> > q;

int map[1000][1000];
int visit[1000][1000];

//�����¿�
int rowtemp[] = { -1,1,0,0 };
int coltemp[] = { 0,0,-1,1 };

bool isValid(int a, int b) {
	if (a >= 0 && a < m && b >= 0 && b < n)
		return true;
	else
		return false;
}

void bfs() {
	//map[a][b] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int dx = x + coltemp[i];
			int dy = y + rowtemp[i];

			if (isValid(dx, dy) && visit[dy][dx] == -1 && map[dy][dx] == 0)
			{
				visit[dy][dx] = visit[y][x] + 1;
				//map[dy][dx] = 1;
				q.push({ dy,dx });
			}
		}

	}
}

void searchStart() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				visit[i][j] = 0;
				q.push({ i,j }); //���Ⱑ �ٽ�!
			}
		}
	}
}

int main() {
	scanf("%d %d", &m, &n);

	//�丶�� �Է¹ޱ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			visit[i][j] = -1;
		}
	}
	searchStart();
	bfs();
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visit[i][j];
		}
		cout << "\n";
	}*/

	int day=0;
	//��¥�� ���ϱ� => visit�� �ִ�
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			day = max(day, visit[i][j]);
		}
	}

	//�����ִ� �丶�� �ִ��� Ȯ��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0&&visit[i][j]==-1)
				day = -1;
		}
	}

	cout << day;

}