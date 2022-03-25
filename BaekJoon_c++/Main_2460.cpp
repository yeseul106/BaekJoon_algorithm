#include <iostream>
#include <cstdio>
#pragma warning (disable:4996)
using namespace std;

int main() {
	
	int passenger = 0;
	int max_cnt = 0;

	// 10개의 역에서 탑승객 정보 입력 받기
	for (int i = 0; i < 10; i++) {
		int in, out;
		scanf("%d %d", &out, &in);

		passenger = passenger - out + in;

		if (max_cnt < passenger) {
			max_cnt = passenger;
		}
	}

	printf("%d\n", max_cnt);
}