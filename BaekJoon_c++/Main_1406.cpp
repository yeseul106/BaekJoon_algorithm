#include <cstdio>
#include <iostream>
#include <string>
#include <stack>
using namespace std;
#pragma warning (disable:4996)

//ó�� swich ������ ���� ���� �翬�� �ð��ʰ�...
//������ �̿��ϸ� ���ڴٴ� ������ �����. Ŀ���� �������� ���� ���ڿ��� ������ ���ڿ� ��Ƴ���
int main() {
	stack<char> lefts,rights;
	string s;
	cin >> s;

	int M;
	scanf("%d", &M);
	int index = s.length() + 1;

	//ó�� Ŀ���� �� ����! �׷��ٸ� ó������ ��� left���ÿ� �������
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
	//������� ������ֱ� ���� rights �������� �Ű��ֱ�
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