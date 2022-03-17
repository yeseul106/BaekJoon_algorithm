#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int N;
vector<int> arr;

void insert(int num) {
	arr.push_back(num);
	int child = arr.size();
	
	while (true) {
		int parent = child / 2;

		// ���ǿ� �����ϰų� �߰��� ��尡 ��Ʈ�� �����ϸ� break
		if (parent <= 0 || (abs(arr.at(parent-1)) < abs(arr.at(child-1))))
			break;
		else if (abs(arr.at(parent-1)) == abs(arr.at(child-1))) {
			if (arr.at(parent-1) > arr.at(child-1)) {
				// �θ� ���� �ڽ� ��� �ٲٱ�
				int tmp = arr.at(parent-1);
				arr.at(parent-1) = arr.at(child-1);
				arr.at(child-1) = tmp;
			}
		}
		else if (abs(arr.at(parent-1)) > abs(arr.at(child-1))) {
			// �θ� ���� �ڽ� ��� �ٲٱ�
			int tmp = arr.at(parent-1);
			arr.at(parent-1) = arr.at(child-1);
			arr.at(child-1) = tmp;
		}
		
		child = parent;
	}
}

void erase() {
	if (arr.size() <=0 )
		cout << "0" << endl;
	else {
		cout << arr.at(0) << endl;
	}

	// ------------------- ���� ���� ���� �κ�
	// ���� �� ������ �ٽ� ���־�� ��

	// 1. Ʈ���� ���� ������ ��带 ��Ʈ �ڸ��� ����
	arr.at(0) = arr.at(arr.size() - 1);
	arr.erase(arr.begin() + arr.size() - 1);

	// 2. �ٲ� ��ġ�� ��尡 ���� ������ �������� �ʴ´ٸ� ���� ���� ������ ��� �� �� ���� ���� �ٲٱ�
	while(true){
		

	return;
}

int main() {

	ios_base::sync_with_stdio(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		// 0 �� �ƴ϶�� �߰� ����
		if (num != 0)
			insert(num);
		else
			erase();
	}

}