#include <iostream>
#include <vector>
#include <string>
#pragma warning (disable:4996)
using namespace std;

int main() {
	string answer;
	string input;

	ios_base::sync_with_stdio(0);

	getline(cin, input);

	int X_len = 0;
	bool flag = false; //X�� ���۵Ǵ��� Ȯ���ϱ� ����
	
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == 'X') {
			if (!flag) // X�� ����
				flag = true;
			X_len++;
		}
		else if (input[i] == '.') {
			if (flag) { // X�� ��
				flag = false;
				
				while(X_len)
			}
		}
	}
}