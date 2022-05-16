#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		bool isVPS = true;
		stack<char> parenthesis;
		string s;
		cin >> s;

		for (int idx = 0; idx < s.length(); idx++) {
			if (s[idx] == '(') { // ���� ��ȣ�� ���, ���ÿ� ����
				parenthesis.push('(');
			}
			else if (s[idx] == ')') { // �ݴ� ��ȣ�� ���, ���ÿ��� ��ȣ �ϳ� ������
				if (parenthesis.empty()) { // ������ ������� ���, VPS �ƴ�
					//cout << "NO" << endl;
					isVPS = false;
				}
				else {
					parenthesis.pop();
				}
			}
		}

		if (!parenthesis.empty() || !isVPS) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
}