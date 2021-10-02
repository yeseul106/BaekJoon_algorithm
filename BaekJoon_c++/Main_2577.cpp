#include <iostream>
#include <string>
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;

	int result;
	result = A * B * C;
	string s = to_string(result); // int -> string

	for (int i = 0; i < 10; i++) {
		int num = 0;

		for (int j = 0; j < s.length(); j++) {
			char ch = s.at(j);

			if (ch - '0' == i) {
				num++;
			}
		}

		cout << num << endl;
		
	}

	return 0;
}