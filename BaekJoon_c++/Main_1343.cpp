#include <iostream>
#include <vector>
#include <string>
#pragma warning (disable:4996)
using namespace std;

int main() {
	string answer="";
	string input;

	ios_base::sync_with_stdio(0);

	getline(cin, input);
	//cout << input << endl;

	int X_len = 0;
	bool flag = false; // X�� ���۵Ǵ��� Ȯ���ϱ� ����
	
	for (int i = 0; i < input.length(); i++) {

		if (input[i] == 'X') {
			if (!flag) { // X�� ����
				flag = true;
			}
			X_len++;
			//cout << "X_len : " << X_len << endl;
		}
		else if (input[i] == '.') {
			if (flag) { // X�� ��
				flag = false;

				// 4�� ���� ��������
				int AAAA_cnt = X_len / 4;
				X_len = X_len % 4;

				if (AAAA_cnt > 0) {
					answer.append(AAAA_cnt * 4, 'A');
				}

				int BB_cnt = X_len / 2;
				X_len = X_len % 2;

				if (X_len > 0) { // ���� �� ���� ���
					cout << "-1" << endl;
					return 0;
				}
				else {
					answer.append(BB_cnt * 2, 'B');
				}
				answer.append(".");
			}
			else {
				answer.append(".");
			}
		}

		if (i == input.length()-1) {
			// 4�� ���� ��������
			int AAAA_cnt = X_len / 4;
			X_len = X_len % 4;

			if (AAAA_cnt > 0) {
				answer.append(AAAA_cnt * 4, 'A');
			}

			int BB_cnt = X_len / 2;
			X_len = X_len % 2;

			if (X_len > 0) { // ���� �� ���� ���
				cout << "-1" << endl;
				return 0;
			}
			else {
				answer.append(BB_cnt * 2, 'B');
			}
		}

		
	}

	cout << answer << endl;
}