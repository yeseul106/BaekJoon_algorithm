#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int R, C;
	char map[12][12]; // ������ ��µ��� �ʴ� ���� Ž���غ�����.
	cin >> R >> C;

	// ���� �ʱ�ȭ
	for (int r = 0; r < R+2; r++) {
		for (int c = 0; c < C+2; c++) {
			map[r][c] = '.';
		}
	}

	// ���� �Է� �ޱ� ( �����ϴ� �ε��� ���� ! )
	for (int r = 1; r < R + 1; r++) {
		for (int c = 1; c < C + 1; c++) {
			char ch;
			cin >> ch;

			map[r][c] = ch;
		}
	}

	// ���� ����
	char newmap[12][12];
	for (int r = 0; r < R + 2; r++) {
		for (int c = 0; c < C + 2; c++)
			newmap[r][c] = map[r][c];
	}

	// ���� Ž���ϱ�
	for (int r = 1; r < R + 1; r++) {
		for (int c = 1; c < C + 1; c++) {
			int count = 0; // ������ �� �� �ٴٸ� ����

			if (map[r][c] == 'X') {
				if (map[r - 1][c] == '.') // ��
					count++;
				if (map[r][c- 1] == '.') // ��
					count++;
				if (map[r + 1][c] == '.') // ��
					count++;
				if (map[r][c + 1] == '.') // ��
					count++;
				if (count >= 3)
					newmap[r][c] = '.';
			}
		}
	}

	// �ּ� ���� ���� ���ϱ�
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