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
			if (s[idx] == '(') { // 여는 괄호일 경우, 스택에 저장
				parenthesis.push('(');
			}
			else if (s[idx] == ')') { // 닫는 괄호일 경우, 스택에서 괄호 하나 꺼내기
				if (parenthesis.empty()) { // 스택이 비어있을 경우, VPS 아님
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