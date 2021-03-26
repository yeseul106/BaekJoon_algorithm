#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> v;

	//몸무게와 키를 pair로 입력받아 vector에 저장
	for (int i = 0; i < N; i++) {
		int f, s;
		cin >> f >> s;
		pair<int, int> p;

		p.first = f; p.second = s;
		v.push_back(p);
	}

	for (int i = 0; i < N; i++) {
		pair<int, int> standard = v.at(i);
		int k = 0;

		for (int j = 0; j < N; j++) {
			//자신을 제외한 나머지 학생들과 비교
			if (j != i) {
				if (standard.first < v.at(j).first && standard.second < v.at(j).second)
					k++;
			}
		}

		cout << k + 1 << " ";
	}
}