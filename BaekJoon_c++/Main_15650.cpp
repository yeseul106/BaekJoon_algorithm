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
			cout << sequence[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = k; i <= N; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			sequence[count] = i;
			dfs(i + 1, count + 1);
			visited[i] = 0; //모든 경우를 탐색하기 위해서 리셋 해놓기
		}
	}
	
}

int main() {
	scanf("%d %d", &N, &M);
	dfs(1, 0);
}