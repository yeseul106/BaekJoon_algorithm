#include <cstdio>
#include <cmath>
#pragma warning (disable:4996)

//1차원 배열로 퀸이 위치한 열의 위치를 나타내면 2차원 배열 필요 X
int chess[15];
int count = 0;
int N;

//csp 조건 걸기 (가지치기를 하기 위한 조건)
bool check(int row) {

	//같은 행이거나 대각선이면 안됨
	//여기서 대각선이란 행의 차이와 퀸이 놓인 열의 자리 차이가 같은 상황
	for (int i = 0; i < row; i++) {
		if (chess[i] == chess[row] || row - i == abs(chess[row] - chess[i]))
			return false;
	}
	return true;
}

void DFS(int row) {
	//마지막 행까지 수행하면 count+1
	if (row == N) {
		count++;
		return;
	}
	
	for (int i = 0; i < N; i++) {
		chess[row] = i;
		//조건에 성립한다면
		if (check(row)) {
			DFS(row + 1); //그 다음 행을 탐색
		}
	}
}

int main() {
	scanf("%d", &N);
	DFS(0);
	printf("%d", count);
}