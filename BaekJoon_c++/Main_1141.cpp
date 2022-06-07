#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// 구조체 사용하기
struct type_str {
	string str;
	int len;

	type_str(string s, int n) {
		str = s;
		len = n;
	}

	// 단어의 정렬은 문자열의 길이로 정렬해야하기 때문에
	bool operator<(const type_str &d) {
		return len < d.len;
	}
};


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; // 단어의 개수
	int cnt_prefix = 0; // 접두사가 되는 단어 개수
	cin >> N;

	vector<type_str> word; // 단어들을 벡터에 저장

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		word.push_back(type_str(tmp, tmp.size()));
	}
	
	// 다른 단어의 접두사가 되는 단어는 다른 단어보다 크기가 작거나 같음
	// 문자열 길이가 짧은 순서대로 정렬하고, 자기 위치보다 뒤에 있는 단어와만 비교하면 됨.

	sort(word.begin(), word.end());
	
	for (int i = 0; i < word.size(); i++) {
		bool hasPrefix = false;
		string str1 = word.at(i).str;

		// 뒤에 있는 단어들과 비교
		for (int j = i + 1; j < word.size(); j++) {
			string str2 = word.at(j).str;

			if (str2.find(str1) == 0) { // 찾음
				hasPrefix = true;
			}
		}
		if (hasPrefix)
			cnt_prefix++;
	}

	cout << N - cnt_prefix << endl;

}