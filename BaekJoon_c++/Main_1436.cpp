#include <iostream>
#include <string>
using namespace std;

int main() {
	int title = 665;
	int N;
	int n = 0;

	cin >> N;

	while (true) {
		string s = to_string(title);

		if (s.find("666") != -1) { // ã���� �ش� ���ڿ� ���� ��ġ ����, �ƴϸ� -1
			n++;
		}

		if (N == n) {
			break;
		}

		title++;
	}
	cout << title;
}