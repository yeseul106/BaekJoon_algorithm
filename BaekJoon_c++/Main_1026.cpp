#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main() {
	vector<int> vecA;
	vector<int> vecB;

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		vecA.push_back(tmp);
	}

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		vecB.push_back(tmp);
	}

	sort(vecA.begin(), vecA.end());
	sort(vecB.begin(), vecB.end());
	reverse(vecB.begin(), vecB.end());

	int sum=0;
	for (int i = 0; i < N; i++) {
		sum += vecA.at(i) * vecB.at(i);
	}

	cout << sum;
	


}