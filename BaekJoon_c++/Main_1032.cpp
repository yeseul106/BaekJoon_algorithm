#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);

	int N;
	vector<string> vec;
	string result = "";

	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >>  str;

		vec.push_back(str);
	}

	for (int i = 0; i < vec[0].length(); i++) {
		char ch = vec[0].at(i);
		bool issame = true;

		for (int j = 0; j < N; j++) {
			if (ch != vec[j].at(i)) {
				issame = false;
				break;
			}
		}

		if (issame)
			result += ch;
		else
			result += '?';
	}

	cout << result << endl;
}