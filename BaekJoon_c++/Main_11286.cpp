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

		// 조건에 만족하거나 추가된 노드가 루트에 도달하면 break
		if (parent <= 0 || (abs(arr.at(parent-1)) < abs(arr.at(child-1))))
			break;
		else if (abs(arr.at(parent-1)) == abs(arr.at(child-1))) {
			if (arr.at(parent-1) > arr.at(child-1)) {
				// 부모 노드와 자식 노드 바꾸기
				int tmp = arr.at(parent-1);
				arr.at(parent-1) = arr.at(child-1);
				arr.at(child-1) = tmp;
			}
		}
		else if (abs(arr.at(parent-1)) > abs(arr.at(child-1))) {
			// 부모 노드와 자식 노드 바꾸기
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

	// ------------------- 내가 생각 못한 부분
	// 삭제 후 정렬을 다시 해주어야 함

	// 1. 트리의 가장 마지막 노드를 루트 자리로 삽입
	arr.at(0) = arr.at(arr.size() - 1);
	arr.erase(arr.begin() + arr.size() - 1);

	// 2. 바꾼 위치의 노드가 힙의 조건을 만족하지 않는다면 왼쪽 노드와 오른쪽 노드 중 더 작은 값과 바꾸기
	while(true){
		

	return;
}

int main() {

	ios_base::sync_with_stdio(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;

		// 0 이 아니라면 추가 연산
		if (num != 0)
			insert(num);
		else
			erase();
	}

}