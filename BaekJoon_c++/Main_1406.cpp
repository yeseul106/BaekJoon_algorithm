#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
using namespace std;
#pragma warning (disable:4996)

//처음 swich 문으로 했을 때는 당연히 시간초과...
//스택을 이용하면 좋겠다는 생각이 들었다. 커서를 기준으로 왼쪽 문자열과 오른쪽 문자열 담아놓기
int main() {
	stack<char> lefts,rights;
	string s;
	cin >> s;

	int M;
	scanf("%d", &M);
	int index = s.length() + 1;

	//처음 커서는 맨 뒷줄! 그렇다면 처음에는 모두 left스택에 담겨있음
	for (int i = 0; i < s.length(); i++) {
		lefts.push(s.at(i));
	}
	while (M != 0) {
		char ch;
		cin >> ch;
		//cout << "ch: " << ch << endl;
		switch (ch)
		{
		case 'L':
			if (!lefts.empty()) {
				rights.push(lefts.top());
				lefts.pop();
			}
			break;
		case 'D':
			if (!rights.empty()) {
				lefts.push(rights.top());
				rights.pop();
			}
			break;
		case 'B':
			if (!lefts.empty()) {
				lefts.pop();
			}
			break;
		case 'P':
			char ch2;
			cin >> ch2;
			lefts.push(ch2);
			break;
		}
		M--;
	}
	string result="";
	int leftsize = lefts.size();
	//순서대로 출력해주기 위해 rights 스택으로 옮겨주기
	for (int i = 0; i < leftsize; i++) {
		rights.push(lefts.top());
		lefts.pop();
	}
	int rightsize = rights.size();
	for (int i = 0; i < rightsize; i++) {
		result += rights.top();
		rights.pop();
	}
	cout << result;

}