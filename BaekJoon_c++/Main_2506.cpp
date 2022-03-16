#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	vector<int> answer;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		answer.push_back(tmp);
	}

	int score = 0;
	int continuity = 0; // 연속해서 맞추는지 확인하기 위한 변수

	for (int i = 0; i < N; i++) {
		if((answer.at(i) == 0) && (continuity != 0)) {
			continuity = 0;
		}
		else if (answer.at(i) == 1) {
			if (continuity != 0)
			{
				continuity++;
				score += continuity;
			}
			else if (continuity == 0) {
				score++;
				continuity++;
			}
		}

		//cout << i << "번째: " << score << endl;
	}

	cout << score << endl;
}