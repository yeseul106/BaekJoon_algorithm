#include <iostream>
#include <queue>
using namespace std;

int main() {

	int score[101];

	int test;
	cin >> test; // 테스트케이스 갯수

	for (int i = 0; i < test; i++) {
		queue<pair<int, int>> Q;
		int n, m;
		int count = 0;
		cin >> n >> m; // n: 문서의 개수, m: 궁금한 문서의 위치
		cout << "n: " << n << " m: " << m << endl;

		for (int j = 0; j < n; j++) {
			int tmp;
			pair<int, int> document;
			cin >> tmp;
			document = pair<int, int>(j, tmp);

			score[j] = tmp;
			Q.push(document); //큐에 집어넣기
		}

		// 큐 돌면서 정렬하기
		for (int k = 0; k < Q.size(); k++) {
			int num = Q.front().second; // 현재 큐의 첫번쨰 원소

			for (int check = k + 1; check < Q.size(); check++) {
				if (num < score[check]) { // 큐의 맨 앞 원소보다 더 큰 문서가 있을 때
					pair<int, int> temp = Q.front();
					Q.pop(); //앞의 원소 삭제
					Q.push(temp);
					break;
				}
			}
		}

		for (int k = 0; k < Q.size(); k++) {
			pair<int,int> num = Q.front();
			count++;
			if (num.first == m) {
				cout << count << endl;
				break;
			}
		}

	}

}