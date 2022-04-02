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
	bool flag = false; //X가 시작되는지 확인하기 위해
	
	for (int i = 0; i < input.length(); i++) {
		if (input[i] == 'X') {
			if (!flag) // X가 시작
				flag = true;
			X_len++;
		}
		else if (input[i] == '.') {
			if (flag) { // X가 끝
				flag = false;
				
				while(X_len)
			}
		}
	}
}