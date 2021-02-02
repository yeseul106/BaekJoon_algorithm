#include <stdio.h>
#define MAX_ELEMENT 1000
#include <queue>
using namespace std;

priority_queue<long long int, vector<long long int>, greater<long long int>> minheap;

// Heap Sorting
inline void heapSort(long long int a[], int n, int m)
{
	for (int i = 0; i < n; i++)	      // minheap ����
		minheap.push(a[i]);		  // n���� insert ���� 

	for (int i = 0; i < m; i++) {
		long long int n1 = minheap.top(); minheap.pop();
		long long int n2 = minheap.top(); minheap.pop();
		long long int tmp = n1 + n2;
		minheap.push(tmp);
		minheap.push(tmp);
	}

	for (int i = 0; i < n; i++)       // ��Ʈ �����Ͽ� �迭�� ����
	{
		a[i] = minheap.top(); minheap.pop();
	}   // ������ min ���� �迭�� �պ��� ä���.
}

int main()
{

	int n, m;
	scanf("%d%d", &n, &m);

	long long int array[MAX_ELEMENT];

	for (int i = 0; i < n; i++)
		scanf("%lld", &array[i]);

	heapSort(array, n, m);

	long long int result = 0;

	for (int i = 0; i < n; i++)
		result += array[i];

	printf("%lld", result);

	return 0;
}