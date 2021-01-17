#include <cstdio>
#include <iostream>
#pragma warning (disable:4996)
using namespace std;

static void sortGapInsertion(int list[], int first, int last, int gap) {
	int i, j, key;
	for (i = first + gap; i <= last; i = i + gap) {
		key = list[i];
		for (j = i - gap; j >= first && list[j] > key; j = j - gap)
			list[j + gap] = list[j];
		list[j + gap] = key;
	}
}

void shell_sort(int list[], int n) {
	int i, gap, count = 0;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		if (gap % 2 == 0) gap++;
		for (i = 0; i < gap; i++)
			sortGapInsertion(list, i, n - 1, gap);
	}
}

int main() {
	int n;
	int j = 0;
	scanf("%d", &n);
	int* list = new int[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &j);
		list[i] = j;
	}
	shell_sort(list, n);

	long long result = 0;
	for (int i = 0; i < n; i++) {
		result += abs((i + 1) - list[i]);
	}

	printf("%ld", result);
	return 0;
}
