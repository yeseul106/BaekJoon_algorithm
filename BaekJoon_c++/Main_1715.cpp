#include<stdio.h>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> minheap;

int main() {

	int n;
	scanf("%d", &n);

	if (n == 1)
	{
		printf("%d", 0);
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		minheap.push(k);
	}

	int tmp = 0;
	int result = 0;

	while (true) {
		int n1 = minheap.top(); minheap.pop(); 
		int n2 = minheap.top(); minheap.pop();
		tmp = n1 + n2;
		if (minheap.size()==0)
		{
			result += tmp;
			break;
		}
		minheap.push(tmp);
		result += tmp;
	}
	printf("%d", result);
	return 0;
}
