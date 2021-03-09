#include <iostream>
using namespace std;

int n; //��ü ����� ��
int family[101][101] = { 0 };//���� ���赵
int result = -1; //�̼�
int visited[101] = { 0 }; //��� �湮�ߴ���

void dfs(int parent, int child, int cnt) {
	if (parent == child) {
		result = cnt; //���� Ž������ ���(parent)�� ��ǥ�� child�� �������� ���� (��ǥ ��忡 ����!)
		return;
	}
	visited[parent] = 1; //�湮�ߴٰ� ǥ��

	for (int i = 0; i < n; i++) {
		if (family[parent][i] == 1 && visited[i] == 0) {
			dfs(i, child, cnt+1); //���� Ž�� ��忡�� ����� ��带 Ž���ϱ� ���� dfs ȣ��
		}
	}
}

int main() {
	cin >> n;
	int a, b; //�̼��� ���ؾ��ϴ� ����� ��ȣ
	cin >> a >> b;
	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int parent, child;
		cin >> parent >> child;
		//�ε����� 1 ������ ����!
		family[parent - 1][child - 1] = 1;
		family[child - 1][parent - 1] = 1;
	}
	dfs(a-1, b-1, 0); //�ε����� �Ѱܾ��ϹǷ� -1
	cout << result; //result�� -1�� �ʱ�ȭ �߱� ������ ģô���� ������(���� �ȵǾ�������) -1

	return 0;
}