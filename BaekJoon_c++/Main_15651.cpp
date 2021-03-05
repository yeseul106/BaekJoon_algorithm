#include <iostream>
#include <cstdio>
#pragma warning (disable:4996)
using namespace std;

int N, M;
int visited[8];
int sequence[8];

void dfs(int k, int count) {
	if (count == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", sequence[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++) {
			sequence[count] = i;
			dfs(i + 1, count + 1);
	}
}

int main() {
	scanf("%d %d", &N, &M);
	dfs(1, 0);
}