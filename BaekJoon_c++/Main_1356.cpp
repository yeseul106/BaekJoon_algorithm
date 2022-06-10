#include <iostream>
#include <string>
using namespace std;

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	// int N;
	// cin >> N;

	string N_str;
	cin >> N_str;

	bool result = false;

	// N_str = to_string(N);

	for (int i = 0; i < N_str.length()-1; i++) {

		int front=1;
		int back=1;

		for (int a = 0; a <= i; a++) {
			front *= (N_str.at(a) - '0');
		}

		for (int b= i+1; b<N_str.length(); b++) {
			back *= (N_str.at(b) - '0');
		}

		if (front == back) {
			result = true;
			break;
		}
			
	}

	if (result)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}