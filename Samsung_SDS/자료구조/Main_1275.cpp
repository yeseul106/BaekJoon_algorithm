#include <iostream>
#include <bits/stdc++.h>
#include <stdio.h>
#pragma warning(disable: 4996)

using namespace std;

int N, Q;
int Base; // Base index ��

//Ʈ���� ��� ������ 2 * Base���� ������ Ȯ��
long long* tree;

//���� ����Ǿ��� �� ������Ʈ �ϴ� �Լ�
void update(int point, long long value) {
	int index = Base + point - 1;

	//1.�����ϰ��� �ϴ� ���� �ε��� �ٲٱ�
	tree[index] = value;

	//2.�θ�� �̵��ؼ� �ڽ� ��� ���� ������ ���� => root���� �ݺ�
	while (index > 0) {
		index = index / 2;

		tree[index] = tree[index * 2] + tree[index * 2 + 1];
	}

}

//������ �־����� �� �������� ���ϴ� �Լ�
long long lgsum(int l, int r) {

	if (l > r) {
		int tmp = l;
		l = r;
		r = tmp;
	}

	//tree������ l�� r ������ index ���ϱ�
	int tree_l = Base + l - 1;
	int tree_r = Base + r - 1;

	long long sum = 0;

	while (tree_l <= tree_r) {
		//left�� �����ʿ� ���� ���� ���� ���ϱ� (index�� Ȧ���� ��)
		if (tree_l % 2 != 0) {
			sum += tree[tree_l];
		}
		//right�� ���ʿ� ���� ���� ���� ���ϱ� (index�� ¦���� ��)
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

	//Base index ���� 1���ٰ� N���� Ŀ�������� 2�� ���Ѵ�.
	for (Base = 1; Base < N; Base *= 2);
	//printf("%d", Base);

	tree = new long long[2 * Base + 1]();

	//Ʈ���� �� �ֱ�
	for (int i = 0; i < N; i++)
	{
		long long tmp;
		cin >> tmp;
		tree[Base + i] = tmp;
	}

	//�θ� ���� ä��� (index�� Base-1���� 1����)
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