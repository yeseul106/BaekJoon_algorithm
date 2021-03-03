#include <cstdio>
#include <cmath>
#pragma warning (disable:4996)

//1���� �迭�� ���� ��ġ�� ���� ��ġ�� ��Ÿ���� 2���� �迭 �ʿ� X
int chess[15];
int count = 0;
int N;

//csp ���� �ɱ� (����ġ�⸦ �ϱ� ���� ����)
bool check(int row) {

	//���� ���̰ų� �밢���̸� �ȵ�
	//���⼭ �밢���̶� ���� ���̿� ���� ���� ���� �ڸ� ���̰� ���� ��Ȳ
	for (int i = 0; i < row; i++) {
		if (chess[i] == chess[row] || row - i == abs(chess[row] - chess[i]))
			return false;
	}
	return true;
}

void DFS(int row) {
	//������ ����� �����ϸ� count+1
	if (row == N) {
		count++;
		return;
	}
	
	for (int i = 0; i < N; i++) {
		chess[row] = i;
		//���ǿ� �����Ѵٸ�
		if (check(row)) {
			DFS(row + 1); //�� ���� ���� Ž��
		}
	}
}

int main() {
	scanf("%d", &N);
	DFS(0);
	printf("%d", count);
}