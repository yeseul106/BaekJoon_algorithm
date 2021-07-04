#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


// 1. ���� �� �ִ��� ���� �������� end-1���� ������ ���� �� ����.
// ������ ������������ ������ ����, ���̿� ������ ��ġ�Ѵ�. (�迭�� �̿�)

int main() {

	int n;
	cin >> n;
	 
	vector<pair<int, int>> assignment;
	int todo[1001];

	// todo �迭 �ʱ�ȭ ��Ű��
	for (int i = 0; i < 1001; i++) {
		todo[i] = 0;
	}

	for (int i = 0; i < n; i++) {
		int a, b;
		pair<int, int> p;

		cin >> p.second >> p.first;

		assignment.push_back(p);
	}


	// ���� - ��������
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

