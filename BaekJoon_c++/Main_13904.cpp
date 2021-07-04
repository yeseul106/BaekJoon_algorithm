#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// 1. 디데이 중 최대인 디데이 기준으로 end-1개의 과제를 택할 수 있음.
// 점수를 내림차순으로 정리한 다음, 디데이에 가깝게 배치한다. (배열을 이용)

int main() {

	int n;
	cin >> n;
	 
	vector<pair<int, int>> assignment;
	int todo[1001];

	// todo 배열 초기화 시키기
	for (int i = 0; i < 1001; i++) {
		todo[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		int a, b;
		pair<int, int> p;

		cin >> p.second >> p.first;

		assignment.push_back(p);
	}


	// 정렬 - 내림차순
	sort(assignment.begin(), assignment.end(), greater<>());
	
	for (int i = 0; i < n; i++) {
		//cout << assignment.at(i).first << " " << assignment.at(i).second << endl;
		int w = assignment.at(i).first;
		int d = assignment.at(i).second;
		int index = d;

		if (todo[d] == 0) {
			todo[d] = w;
		}
		else {
			for (int k = d - 1; k > 0; k--) {
				if (todo[k] == 0) {
					todo[k] = w;
					break;
				}
			}
		}
	}
	
	int result = 0;

	for (int i = 1; i < 1001; i++) {
		result += todo[i];
	}

	cout << result;

}

