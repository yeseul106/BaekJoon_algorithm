#include <iostream>
#include <deque>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	
	deque<pair<int,int>> balloons;
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		balloons.push_back(make_pair(tmp,i+1)); // 이동할 칸 수, 현재 index
	}

	// 덱을 회전시켜준다는 생각을 하면 됨
	while (true) {
		int next = balloons.front().first;
		cout << balloons.front().second << " ";

		balloons.pop_front();

		if (balloons.empty())
			break;

		if (next > 0) {
			for (int i = 0; i < next - 1; i++) {
				balloons.push_back(balloons.front());
				balloons.pop_front();
			}
		}
		else {
			for (int i = next; i < 0; i++) {
				balloons.push_front(balloons.back());
				balloons.pop_back();
			}
		}
	}

}