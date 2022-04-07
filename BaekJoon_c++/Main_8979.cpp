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
		scanf("%d %d %d %d", &num, &gold, &silver, &bronze);

		vector<int> tmp;
		tmp.push_back(gold);
		tmp.push_back(silver);
		tmp.push_back(bronze);

		countries[num] = tmp;
	}

	// K ������ �޴� ���� �������� ��
	vector<int> k_vec = countries[K];
	int isChanged[1001] = { 0 };

	int rank = 1;

	for (int medal = 0; medal < 3; medal++) { // ��,��,�� ������ ��
		for (int n = 1; n <= N; n++) {
			if (isChanged[n]==0 && k_vec.at(medal) < countries[n].at(medal)) { // n ���� k ���󺸴� ����� ���� ������, k ���� �޴��� �� ����
				if (medal != 0){
					if (k_vec.at(medal - 1) < countries[n].at(medal - 1)) {
						rank++;
						isChanged[n] = 1;
					}
					else {
						continue;
					}
				}
				else {
					rank++;
					isChanged[n] = 1;
				}
				//cout << "medal: " << medal << " n: " << n << " rank: " << rank << endl;
			}
		}
	}

	cout << rank << endl;
}