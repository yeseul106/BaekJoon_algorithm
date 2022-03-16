#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);

	vector<pair<int, int>> points;
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		pair<int, int> p = pair<int, int>(a, b);
		points.push_back(p);
	}

	int result = 0;

	for (int i = 0; i < N; i++) {
		pair<int, int> point1 = points.at(i);

		for (int j = i + 1; j < N; j++) {

			pair<int, int> point2 = points.at(j);
			// x축 값이 같은 경우
			if ((point1.first == point2.first) && (point1.second != point2.second)) {
				result++;
			}

			// y축 값이 같은 경우
			if ((point1.first != point2.first) && (point1.second == point2.second)) {
				result++;
			}
		}
	}

	cout << result << endl;
}