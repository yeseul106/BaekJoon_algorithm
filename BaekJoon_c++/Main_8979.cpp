#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#pragma warning (disable:4996)
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;

	// �� ������ �޴� ������ vector�� ����
	vector<int> countries[1001]; 

	// N: ������ ��, K: ����� �˰� ���� ����
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		int num, gold, silver, bronze;
		// scanf("%d %d %d %d", &num, &gold, &silver, &bronze);
		// ios_base::sync_with_stdio(0)�� ���� scanf�� cin ��� ���Ұ� => ��Ÿ�� ���� �߻�
		cin >> num >> gold >> silver >> bronze;

		vector<int> tmp;
		tmp.push_back(gold);
		tmp.push_back(silver);
		tmp.push_back(bronze);

		countries[num] = tmp;
	}

	// K ������ �޴� ���� �������� ��
	vector<int> k_vec = countries[K];
	//int isChanged[1001] = { 0 };

	int rank = 1;

	for (int n = 1; n <= N; n++) {
		if (n == K)
			continue;

		if (k_vec.at(0) < countries[n].at(0)) {
			rank++;
		}
		else if (k_vec.at(0) == countries[n].at(0)) {
			if (k_vec.at(1) < countries[n].at(1)) {
				rank++;
			}
			else if (k_vec.at(1) == countries[n].at(1)) {
				if (k_vec.at(2) < countries[n].at(2)) {
					rank++;
				}
			}
		}
	}

	cout << rank << endl;
}