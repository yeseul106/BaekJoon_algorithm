#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> v;

	//�����Կ� Ű�� pair�� �Է¹޾� vector�� ����
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
			//�ڽ��� ������ ������ �л���� ��
			if (j != i) {
				if (standard.first < v.at(j).first && standard.second < v.at(j).second)
					k++;
			}
		}

		cout << k + 1 << " ";
	}
}