#include <iostream>
#define INF 987654321
using namespace std;

int n, k;
int coin[101];
int DP[10001];

void DynamicPrograming() {

        for (int i = 1; i <=n; i++) {
            for (int j = coin[i]; j <= k; j++) {
                DP[j] = min(DP[j], DP[j - coin[i]]+1);
            }
        }

        if (DP[k] == INF) {
            cout << -1;
        }
        else {
            cout << DP[k];
        }
}

int main() {

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	for (int i = 1; i <= k; i++) {
		DP[i] = INF;
	}

	DynamicPrograming();
}