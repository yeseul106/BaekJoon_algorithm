#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#pragma warning(disable: 4996)

using namespace std;

int N, Q;
int Base; // Base index 값

//트리의 노드 개수는 2 * Base개의 공간을 확보
long long* tree;

//값이 변경되었을 때 업데이트 하는 함수
void update(int point, long long value) {
	int index = Base + point - 1;

	//1.변경하고자 하는 값의 인덱스 바꾸기
	tree[index] = value;

	//2.부모로 이동해서 자식 노드 값의 합으로 갱신 => root까지 반복
	while (index > 0) {
		index = index / 2;

		tree[index] = tree[index * 2] + tree[index * 2 + 1];
	}

}

//구간이 주어졌을 때 구간합을 구하는 함수
long long lgsum(int l, int r) {

	if (l > r) {
		int tmp = l;
		l = r;
		r = tmp;
	}

	//tree에서의 l과 r 각각의 index 구하기
	int tree_l = Base + l - 1;
	int tree_r = Base + r - 1;

	long long sum = 0;

	while (tree_l <= tree_r) {
		//left는 오른쪽에 있을 때만 값을 취하기 (index가 홀수일 때)
		if (tree_l % 2 != 0) {
			sum += tree[tree_l];
		}
		//right는 왼쪽에 있을 때만 값을 취하기 (index가 짝수일 때)
		if (tree_r % 2 == 0) {
			sum += tree[tree_r];
		}

		tree_l = (tree_l + 1) / 2;
		tree_r = (tree_r - 1) / 2;
	}

	return sum;
}

int main() {

	scanf("%d %d", &N, &Q);

	//Base index 값은 1에다가 N보다 커질때까지 2를 곱한다.
	for (Base = 1; Base < N; Base *= 2);
	//printf("%d", Base);

	tree = new long long[2 * Base + 1]();

	//트리에 값 넣기
	for (int i = 0; i < N; i++)
	{
		long long tmp;
		cin >> tmp;
		tree[Base + i] = tmp;
	}

	//부모 노드들 채우기 (index가 Base-1부터 1까지)
	for (int i = Base - 1; i > 0; i--) {
		tree[i] = tree[i * 2] + tree[i * 2 + 1];
	}


	for (int i = 0; i < Q; i++) {
		int x, y, a;
		long long b;
		scanf("%d %d %d %lld", &x, &y, &a, &b);

		printf("%lld \n", lgsum(x, y));
		update(a, b);
	}

	return 0;
}