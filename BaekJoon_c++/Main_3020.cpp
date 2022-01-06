#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#pragma warning (disable: 4996)
#define SIZE_MAX 500001

int N, H;
int stalagmite[SIZE_MAX] = { 0 }; //����
int stalactite[SIZE_MAX] = { 0 }; //������
vector<int> block;

int main() {
	scanf("%d %d", &N, &H);

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;

		//������ ���̶�� �����ϱ�
		//Ȧ����° �Է��̸� ����
		if (i % 2 == 0) {
			stalagmite[tmp]++;
		}
		//¦����° �Է��̸� ������
		else { stalactite[tmp]++; }
	}

	for (int i = H - 1; i >= 1; i--) {
		stalactite[i] += stalactite[i + 1];
		stalagmite[i] += stalagmite[i + 1];
	}

	//�νô� ��ֹ��� ������ ���̿� ���� ����ϱ�
	for (int i = 1; i <= H; i++) {
		int num = stalagmite[i] + stalactite[H - i +1];
		block.push_back(num);
	}

	sort(block.begin(), block.end());

	//for (int i = 0; i < block.size(); i++) {
	//	printf("%d ", block.at(i));
	//}

	int cnt = 1;
	for (int i = 1; i <= block.size(); i++) {
		if (block.at(i - 1) == block.at(i))
			cnt++;
		else
			break;
	}

	printf("%d %d", block.at(0), cnt);

	return 0;
}