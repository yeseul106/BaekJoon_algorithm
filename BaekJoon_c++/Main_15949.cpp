#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
#pragma warning (disable:4996)

int N, M;
int visited[10];
int sequence[10];

void dfs(int k, int count) {
	if (count == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", sequence[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			sequence[count] = i;
			dfs(i, count + 1);
			visited[i] = 0; //ÃÊ±âÈ­
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	dfs(1, 0);
}