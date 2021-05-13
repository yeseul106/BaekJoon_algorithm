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
	//벡터 내의 중복 요소 제거를 생각 못했음.
	//unique 함수와 erase 함수를 이용하여 벡터의 중복 요소를 제거
	sort_v.erase(unique(sort_v.begin(), sort_v.end()), sort_v.end());

	//for (int i = 0; i < N; i++) {
	//	int tmp = v.at(i);
	//	//find 함수를 이용하면 iterator 반환, iterator 끼리 빼면 인덱스 구할 수 있다!
	//	printf("%d ", find(sort_v.begin(), sort_v.end(), tmp) - sort_v.begin()) ;
	//}

	//이 문제는 단순히 find하면 시간 초과 => 이분 탐색으로 해결
	for (int i = 0; i < N; i++) {
		int tmp = v.at(i);
		printf("%d ", find_tmp(tmp));
	}
}