#include <iostream>
#include <string>
using namespace std;

int N;
string grid[101];
int isVisited[101][101];

int delta_x[] = { -1,1,0,0 }; 
int delta_y[] = { 0,0,-1,1 };

bool isValid(int a, int b) {
	// Ž���Ϸ��� X ��ǥ���� Y ��ǥ���� ���� ���� �ִ��� Ȯ��
	return((a >= 0 && a < N) && (b >= 0 && b < N));
}

void normal_DFS(int a, int b) {

	for (int i = 0; i < 4; i++) {

		// �����¿츦 Ž��
		int dy = a + delta_y[i];
		int dx = b + delta_x[i];

		if (isValid(dy, dx) && // ��ǥ���� ��ȿ�ϰ�,
			isVisited[dy][dx] == 0 && // ������ �湮�� ���� ������,
			grid[dy][dx] == grid[a][b]) { // ���� char ���� Ž���ϴ� char ���� ���ٸ�
			
			isVisited[dy][dx] = 1;
			normal_DFS(dy, dx);
		}

	}
}

void abnormal_DFS(int a, int b) {

	for (int i = 0; i < 4; i++) {
		int dy = a + delta_y[i];
		int dx = b + delta_x[i];

		if (isValid(dy, dx) && // ��ǥ���� ��ȿ�ϰ�,
			isVisited[dy][dx] == 0 && // ������ �湮�� ���� ������,
			((grid[dy][dx] == grid[a][b]) || // ���� char ���� Ž���ϴ� char ���� ���ų�
				(grid[dy][dx]=='R' && grid[a][b] == 'G') || // R, G �� ���� ������
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

	// �׷��� Ž�� (DFS) 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (isVisited[i][j] == 0) {
				normal++;  
				isVisited[i][j] = 1;
				normal_DFS(i, j);
			}
		}
	}
	
	// isVisited �迭 �ʱ�ȭ ���ֱ�
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			isVisited[i][j] = 0;

		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (isVisited[i][j] == 0) {
				abnormal++; // ������ ���� + 1
				isVisited[i][j] = 1;
				abnormal_DFS(i, j);
			}
		}
	}

	cout << normal <<" " << abnormal << endl;
}