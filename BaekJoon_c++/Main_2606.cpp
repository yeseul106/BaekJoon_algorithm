//DFS ����Ǯ��
//����: ���� ���̷����� �� ���̷����� ��Ʈ��ũ�� ���� ���ĵȴ�.�� ��ǻ�Ͱ� �� ���̷����� �ɸ��� �� ��ǻ�Ϳ� ��Ʈ��ũ �󿡼� ����Ǿ� �ִ� ��� ��ǻ�ʹ� �� ���̷����� �ɸ��� �ȴ�.
//
//�Է�: ù° �ٿ��� ��ǻ���� ���� �־�����. ��ǻ���� ���� 100 �����̰� �� ��ǻ�Ϳ��� 1�� ���� ���ʴ�� ��ȣ�� �Ű�����. ��° �ٿ��� ��Ʈ��ũ �󿡼� ���� ����Ǿ� �ִ� ��ǻ�� ���� ���� �־�����. 
//      �̾ �� ����ŭ �� �ٿ� �� �־� ��Ʈ��ũ �󿡼� ���� ����Ǿ� �ִ� ��ǻ���� ��ȣ ���� �־�����.
//���: 1�� ��ǻ�Ͱ� �� ���̷����� �ɷ��� ��, 1�� ��ǻ�͸� ���� �� ���̷����� �ɸ��� �Ǵ� ��ǻ���� ���� ù° �ٿ� ����Ѵ�.

#include <iostream>
#include <cstdio>
using namespace std;

int visit[100];
int graph[100][100];
int computer;
int cnt;

void DFS(int a) {
	visit[a] = 1;

	for (int i = 0; i < computer; i++) {
		if (visit[i] != 1 && graph[a][i] == 1)
		{
			cnt++;
			DFS(i);
		}
	}
}

int main() {
	cin >> computer;

	int network;
	cin >> network;

	//�׷��� �ʱ�ȭ �ϱ�
	for (int i = 0; i < computer; i++) {
		visit[i] = 0;
		for (int j = 0; j < computer; j++) {
			graph[i][j] = 0;
		}
	}

	//�׷��� �����ϱ�
	for (int i = 0; i < network; i++) {
		int a, b;
		cin >> a >> b;
		graph[a - 1][b - 1] = 1;
		graph[b - 1][a - 1] = 1;
	}
	cnt = 0;

	DFS(0);
	cout << cnt;

	return 0;
}