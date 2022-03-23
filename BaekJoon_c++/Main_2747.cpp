#include <iostream>
#include <cstdio>
#pragma warning (disable:4996)
#define MAX_N 50
using namespace std;

int N;

void fibonacci(int n) {

	int idx;
	int f[MAX_N];

	f[0] = 0;
	if (n > 0) {
		f[1] = 1;
		for (int i = 2; i <= n; i++) {
			f[i] = f[i - 2] + f[i - 1];
		}
	}

	printf("%d", f[n]);
	
}

int main() {

	scanf("%d", &N);

	fibonacci(N);
}