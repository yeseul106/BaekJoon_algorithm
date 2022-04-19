#include<iostream>
#include <algorithm>

int INF = 1000000007;
using namespace std;

int dp[501][501];
int cost[501];
int sum[501];
int T, K, i;

int main() {
    cin >> T;
    while (T--) {
        cin >> K;

        // 입력 받기
        for (i = 1; i <= K; ++i) {
            cin >> cost[i];
            sum[i] = sum[i - 1] + cost[i];
        }


        for (int d = 1; d < K; d++) { // 구해야 하는 범위의 크기
                        // EX) d가 1이면, 1~2번째 파일, 2~3째 파일... 합칠 때 / d가 2이면 1~3번째 파일, 2~4번째 파일.. 합칠 때
            for (int tx = 1; tx + d <= K; tx++) { // 합치는 범위의 시작 부분
                int ty = tx + d;
                dp[tx][ty] = INF; // tx부터 ty까지 파일들을 합치는데 필요한 최소비용 무한대로 초기화

                for (int mid = tx; mid < ty; mid++) // k는 구해야 하는 범위를 두 부분으로 나누는 기준점
                    dp[tx][ty] = min(dp[tx][ty], dp[tx][mid] + dp[mid + 1][ty] + sum[ty] - sum[tx - 1]);
            }
        }

        cout << dp[1][K] << endl;
    }
    return 0;
}