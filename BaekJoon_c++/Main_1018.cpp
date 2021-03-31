#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	char type[2] = { 'B','W' };

	int N, M;
	cin >> N >> M;

	int min = 12345;

	char input[51][51];

	
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;

		for (int j = 0; j < M; j++) {
			input[i][j] = s[j];
		}
	}

	/*�Է� �� �޾Ҵ��� Ȯ��
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << input[i][j];
		}
		cout << endl;
	}*/

	
	for (int i = 0; i <= N - 8; i++) { // window�� ��������� ��ĭ�� �̵�
		
		for (int j = 0; j <= M - 8; j++) { // window�� ���������� ��ĭ�� �̵�
			int BWcount = 0;
			int WBcount = 0;
			int count = 0;

			int Bindex = 0; // B�� �����϶�
			int Windex = 1; // W�� �����ϋ�

			for (int m = i; m < i + 8; m++) {
				for (int n = j; n < j + 8; n++) {
					if (input[m][n] != type[Bindex % 2]) {
						BWcount++;
					}
					Bindex++;

					if (input[m][n] != type[Windex % 2]) {
						WBcount++;
					}
					Windex++;
				}
				Bindex = Bindex + 1;
				Windex = Windex + 1;
			}

			count = (BWcount >= WBcount) ? WBcount : BWcount;

			if (min > count) {
				min = count;
			}
		}
	}

	cout << min;

	return 0;
}