#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	vector<int> vec;

	cin >> N;

	// ����� ���� �Է� �ޱ�
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}

	int cnt = 0;
	int max = 0;

	for (int i = N-1; i >= 0; i--) {
		// max ���� ����ؼ� ������
		if (max < vec.at(i)) {
			max = vec.at(i);
			cnt++; 
		}
	}

	cout << cnt << endl;

}