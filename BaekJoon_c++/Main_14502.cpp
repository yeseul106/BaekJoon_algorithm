//BaekJoon_14502_ys
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

int map[10][10]; //������
int visit[10][10]; //�湮�ߴ���
int spread[10][10]; //���̷��� ���� ������
int copyMap[10][10]; // ������ ������
int result = 0;
int n, m; //���� n, ���� m


int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void mapCopy(int(*a)[10], int(*b)[10]) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			a[i][j] = b[i][j];
}

bool isValid(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < m)
		return true;
	else
		return false;
}

void BFS() {
	mapCopy(spread, copyMap);
	queue<pair<int, int>> q;

	//�������� �������� ��� ť�� ���� �� �־����! ��¥�� ������� ���� �����Ұ���
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (spread[i][j] == 2)
				q.push({ i,j });
		}
	}

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int newx = x + dx[k];
			int newy = y + dy[k];

			if (isValid(newx, newy)  && spread[newx][newy] == 0)
			{
				q.push({ newx, newy });
				spread[newx][newy] = 2;
			}
		}
	}

	//count �ϱ�
	int count = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (spread[i][j] == 0)
				count+=1;
		}
	}
	
	result = max(result, count);
}

void DFS(int i, int j, int cnt) {
	copyMap[i][j] = 1;

	if (cnt == 3)
	{
		BFS();
		copyMap[i][j] = 0; //���� �� ���󺹱�
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copyMap[i][j] == 0)
			{
				DFS(i,j,cnt + 1);
			}
		}
	}
	copyMap[i][j] = 0; //���� �� ���󺹱�
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			visit[i][j] = 0;
		}
	}

	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0)
			{
				mapCopy(copyMap,map);
				DFS(i, j, 1);
			}
				
		}
	}
	
	cout << result;
}
