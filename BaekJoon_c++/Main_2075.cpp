#include <queue>
#include <cstdio>
#pragma warning(disable:4996
#define MAX_ELE 1500
using namespace std;

int main() {
	priority_queue<long long int, vector<long long int>, greater<long long int>> q;

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		long long int k;
		scanf("%lld", &k);
		q.push(k);
	}

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n; j++) {
			long long int k;
			scanf("%lld", &k);
			if (q.top() < k)
			{
				q.top(); q.pop();
				q.push(k);
			}
		}
	}
	long long int result = q.top();
	printf("%lld", result);

	return 0;
}
