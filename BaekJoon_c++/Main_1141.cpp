#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


// ����ü ����ϱ�
struct type_str {
	string str;
	int len;

	type_str(string s, int n) {
		str = s;
		len = n;
	}

	// �ܾ��� ������ ���ڿ��� ���̷� �����ؾ��ϱ� ������
	bool operator<(const type_str &d) {
		return len < d.len;
	}
};


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; // �ܾ��� ����
	int cnt_prefix = 0; // ���λ簡 �Ǵ� �ܾ� ����
	cin >> N;

	vector<type_str> word; // �ܾ���� ���Ϳ� ����

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		word.push_back(type_str(tmp, tmp.size()));
	}
	
	// �ٸ� �ܾ��� ���λ簡 �Ǵ� �ܾ�� �ٸ� �ܾ�� ũ�Ⱑ �۰ų� ����
	// ���ڿ� ���̰� ª�� ������� �����ϰ�, �ڱ� ��ġ���� �ڿ� �ִ� �ܾ�͸� ���ϸ� ��.

	sort(word.begin(), word.end());
	
	for (int i = 0; i < word.size(); i++) {
		bool hasPrefix = false;
		string str1 = word.at(i).str;

		// �ڿ� �ִ� �ܾ��� ��
		for (int j = i + 1; j < word.size(); j++) {
			string str2 = word.at(j).str;

			if (str2.find(str1) == 0) { // ã��
				hasPrefix = true;
			}
		}
		if (hasPrefix)
			cnt_prefix++;
	}

	cout << N - cnt_prefix << endl;

}