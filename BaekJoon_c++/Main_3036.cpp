#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int first;

int gcd(int a, int b) {
	if (b == 0)return a;
	else return gcd(b, a % b);
}

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;

		if (i == 0)
		{
			first = tmp;
			continue;
		}
		else {
			int gcd_num = gcd(first, tmp);
			printf("%d/%d\n", first / gcd_num, tmp / gcd_num);
		}

	}


}