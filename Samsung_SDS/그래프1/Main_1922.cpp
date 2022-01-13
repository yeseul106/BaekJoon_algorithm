#include <iostream>
#include <queue>
#include <cstdio>
#include <functional>
using namespace std;
#pragma warning (disable:4996)

struct Com {
	int node1;
	int node2;
	int cost;
	Com(int n1, int n2, int c) :node1(n1), node2(n2), cost(c) {}

	//cost�� �������� priority �������� ���� (cost�� ���� ���� top�� ���� �Ѵ�)
	bool operator<(const Com c) const {
		return this->cost > c.cost;
	}
};

priority_queue<Com> pq;
int computer[1001];
int n, m;



void init() {
	for (int i = 0; i <= n; i++) {
		computer[i] = i;
	}
}

int find(int n) {
	if (computer[n] == n) return n;
	else return computer[n] = find(computer[n]);
}


void union_com(int a, int b) {
	computer[find(a)] = find(b);
}

int main() {
	scanf("%d \n", &n);
	scanf("%d \n", &m);
	init();

	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);

		pq.push(Com(a, b, c));
	}

	int result = 0;
	int cnt = 0;

	while(!pq.empty()) {
		if (cnt == n - 1)
			break;
		//�ּ� ���� Ʈ�� ã�� (ũ�罺Į �˰���)
		Com now = pq.top(); pq.pop();

		//�� ��尡 ����Ǿ� ���� ������
		if (find(now.node1) != find(now.node2))
		{
			union_com(now.node1, now.node2);
			result += now.cost;
			cnt++;
		}
		
	}

	printf("%d", result);
}
