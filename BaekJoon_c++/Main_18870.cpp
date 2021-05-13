#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#pragma warning (disable:4996)
using namespace std;

vector<int> v;
vector<int> sort_v;

int find_tmp(int key) {
	int mid = 0;
	int start = 0;
	int end = sort_v.size();

	while (start < end) {
		mid = (start + end) / 2;
		if (sort_v.at(mid) == key)
			return mid;
		else if (sort_v.at(mid) < key) {
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
}

int main() {

	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		v.push_back(temp);
		sort_v.push_back(temp);
	}

	sort(sort_v.begin(), sort_v.end());
	//���� ���� �ߺ� ��� ���Ÿ� ���� ������.
	//unique �Լ��� erase �Լ��� �̿��Ͽ� ������ �ߺ� ��Ҹ� ����
	sort_v.erase(unique(sort_v.begin(), sort_v.end()), sort_v.end());

	//for (int i = 0; i < N; i++) {
	//	int tmp = v.at(i);
	//	//find �Լ��� �̿��ϸ� iterator ��ȯ, iterator ���� ���� �ε��� ���� �� �ִ�!
	//	printf("%d ", find(sort_v.begin(), sort_v.end(), tmp) - sort_v.begin()) ;
	//}

	//�� ������ �ܼ��� find�ϸ� �ð� �ʰ� => �̺� Ž������ �ذ�
	for (int i = 0; i < N; i++) {
		int tmp = v.at(i);
		printf("%d ", find_tmp(tmp));
	}
}