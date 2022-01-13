#include <iostream>
#include <cstdio>
using namespace std;
#pragma warning (disable:4996)
#define SIZE_MAX 1000001

int parent[SIZE_MAX];
int n, m;

void init() {
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
}

int find(int k) {
	if (parent[k] == k) return k;
	else return parent[k] = find(parent[k]); // 경로 압축 !
}

void union_arr(int a, int b) {
	int aroot = find(a);
	int broot = find(b);
	parent[aroot] = broot;
}

int main() {

	scanf("%d %d", &n, &m);
	init();

	for (int i = 0; i < m; i++) {
		int t, a, b;
		scanf("%d %d %d", &t, &a, &b);
		if (t == 0) {
			union_arr(a, b);
		}
		else {
			if (find(b) == find(a)) {
				printf("yes\n");
			}
			else {
				printf("no\n");
			}
			
		}
	}
}
