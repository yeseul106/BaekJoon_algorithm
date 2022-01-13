#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#pragma warning (disable: 4996)
#define SIZE_MAX 500001

int N, H;
int stalagmite[SIZE_MAX] = { 0 }; //석순
int stalactite[SIZE_MAX] = { 0 }; //종유석
vector<int> block;

int main() {
	scanf("%d %d", &N, &H);

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;

		//구간의 합이라고 생각하기
		//홀수번째 입력이면 석순
		if (i % 2 == 0) {
			stalagmite[tmp]++;
		}
		//짝수번째 입력이면 종유석
		else { stalactite[tmp]++; }
	}

	for (int i = H - 1; i >= 1; i--) {
		stalactite[i] += stalactite[i + 1];
		stalagmite[i] += stalagmite[i + 1];
	}

	//부시는 장애물의 갯수를 높이에 따라 계산하기
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