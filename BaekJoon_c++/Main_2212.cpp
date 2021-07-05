#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, k;
	vector<int> sensor;
	vector<int> distance;

	cin >> n;
	cin >> k;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		sensor.push_back(tmp);
	}

	sort(sensor.begin(), sensor.end());

	for (int i = 0; i < n - 1; i++) {
		int tmp = sensor.at(i+1) - sensor.at(i);
		distance.push_back(tmp);
	}

	/*for (int i = 0; i < n - 1; i++) {
		cout << distance.at(i) << " ";
	}*/

	sort(distance.begin(), distance.end());

	int minDistance = 0;

	// 집중국 k개, 센서 n개 ==> n-k개의 센서는 집중국이 부담해야함
	for (int i = 0; i < n-k; i++) {
		minDistance += distance.at(i);
	}

	cout << minDistance;
	return 0;
}