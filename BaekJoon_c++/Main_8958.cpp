#include <iostream>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string ox;
		
		cin >> ox; //공백이 없으므로 cin으로 받아도 무방

		//cout << ox << endl;

		int point = 0;
		int result = 0;

		for (int j = 0; j < ox.length(); j++) {
			if (ox.at(j) == 'O') {
				point++;
				result += point;
			}
			else {
				point = 0;
			}
		}
		cout << result << endl;
	}
}