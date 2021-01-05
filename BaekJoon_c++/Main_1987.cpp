//BaekJoon_1987_ys =>BFS�� Ǯ���!BFS�ȵ� DFS��
//(�� ���� ��ٷο���! ���� �� �صα�!)

#include <iostream>
//#include <queue>
#include <cstdio>
#pragma warning (disable:4996)
using namespace std;

char board[21][21];
int visit[21][21];
//queue<pair<int, int>> q;
int R, C; //R�� ����, C�� ����
int result = 0;
int checkAlpha[26]; //�̹� ������ ���ĺ����� Ȯ���ϴ� �迭

//�����¿�
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

/*�� ������ ������ ���� ���� ���� �� �ִ� �ִ��� ������ ã�� ���̹Ƿ�
��� �������� �����鼭 �ִ밪�� ��������� ���� => ���ĺ��� ��ġ�� �ȵ����� 
���� ���� �� ������. ��ü ��� ��θ� Ž���ؾ��ϹǷ�!
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