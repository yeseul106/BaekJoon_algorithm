#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//큐 출력해보기
void showAll(queue<pair<int,int>> q)
{
	cout << "큐 상태-------------------------" << endl;
	while (!q.empty())
	{
		cout << "inx: " << q.front().first << ' ';
		cout << "value: " << q.front().second << ' ';
		cout << endl;
		q.pop();
	}
	cout << "-------------------------------------" << endl;
}

int main() {
	
	int test;
	cin >> test; // 테스트케이스 갯수

	for (int i = 0; i < test; i++) {
		queue<pair<int, int>> Q;
		queue<pair<int, int>> newQ;
		vector<int> score;

		int n, m;
		int count = 0;
		cin >> n >> m; // n: 문서의 개수, m: 궁금한 문서의 위치
		//cout << "n: " << n << " m: " << m << endl;

		for (int j = 0; j < n; j++) {
			int tmp;
			pair<int, int> document;
			cin >> tmp;
			document = pair<int, int>(j, tmp);

			score.push_back(tmp);
			Q.push(document); //큐에 집어넣기
		}
		
		int idx = 0;
		// 큐 돌면서 정렬하기
		while(!Q.empty()) {
			int num = Q.front().second; // 현재 큐의 첫번째 원소
			bool change = false;

			for (int check = 1; check < Q.size(); check++) {

				if (num < score[check]) { // 큐의 맨 앞 원소보다 더 큰 문서가 있을 때
					pair<int, int> temp = Q.front();
					Q.pop(); //앞의 원소 삭제
					Q.push(temp);

					//벡터의 값도 바꿔주기
					score.erase(score.begin() + 0);
					score.push_back(num);
					change = true;
					break;
				}
			}
			if (!change) {  //더 이상 바꿀 것이 없음
				newQ.push(Q.front());
				Q.pop();
				score.erase(score.begin() + 0);
			}
		}

		//큐 정렬 확인
		//showAll(newQ);

		while(!newQ.empty()) {
			pair<int,int> result = newQ.front();
			count++;
			if (result.first == m) {
				cout << count << endl;
				break;
			}
			newQ.pop();
		}

	}

}