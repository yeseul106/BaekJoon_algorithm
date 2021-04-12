#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int N;
vector<int> arr;
int visited[9]={ 0 };
int tmp[9];
int maxNum = -1;

void dfs(int index, int count) {
	if (count == N) {
		int sum=0;
		for (int i = 0; i < N-1; i++) {
			int sub = abs(tmp[i + 1] - tmp[i]);
			sum += sub;
		}
		if (maxNum < sum) {
			maxNum = sum;
		}
		return;
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			tmp[count] = arr.at(i);
			dfs(i, count+1);
			visited[i] = 0;
		}
	}
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	dfs(0, 0);

	cout << maxNum;
	
}