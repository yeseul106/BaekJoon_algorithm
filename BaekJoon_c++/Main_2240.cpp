#include <iostream>
#include <cstdio>
#include <math.h>
#pragma warning (disable:4996)
using namespace std;

int T, W; // �ڵΰ� �������� �ʼ�, �����̴� Ƚ�� 
int DP[31][2][1001]; // DP[�̵� Ƚ��][�ڵ��� ���� ��ġ][�帥 �ð�]
int drop_tree[1001]; // �ڵΰ� �������� ���� ��ȣ

void init() {
	// �迭 �ʱ�ȭ �߿� !
	for (int j = 0; j <= W; j++) {
		for (int i = 0; i < 2; i++) {
			for (int k = 1; k <= T; k++) {
				DP[j][i][k] = -1;
			}
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio(0);

	scanf("%d %d\n", &T, &W);
	
	for (int i = 1; i <= T; i++) {
		cin >> drop_tree[i];
	}

	init();

	// DP �迭 �����
	for (int i = 0; i <= W; i++) { // �����̴� Ƚ��
		for (int j = 1; j <= T; j++) { // �帣�� �ʼ�

			if (i == 0) { //ó�� ������ 1�� ����, �� 1�� ��ġ�� ���� ä��� ��.
				DP[i][0][j] = DP[i][0][j - 1] + (drop_tree[j]==1);
			}
			else {
				// j�� �������� ��ġ�� 1�� ������ ��
				DP[i][0][j] = max(DP[i][0][j - 1] + (drop_tree[j] == 1), DP[i - 1][1][j - 1] + (drop_tree[j] == 1));
				
				// j�� �������� ��ġ�� 2�� ������ ��
				DP[i][1][j] = max(DP[i][1][j - 1] + (drop_tree[j] == 2), DP[i - 1][0][j - 1] + (drop_tree[j] == 2));

				// max ( �̵��߰� ���� �ڵΰ� �������� ������ �ִ°�?, �̵����� �ʾҰ� ���� �ڵΰ� �������� ������ �ִ°�? )
				// �� �� j-1 ���� DP ���� ������. (1�� ���� ��Ȳ)
			}

		}
	}

	// �ִ� ã��
	int result = 0;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j <= W; j++) {
			result = max(result, DP[j][i][T]);
		}
	}

	cout << result << endl;
}