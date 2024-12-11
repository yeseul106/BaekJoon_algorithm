#include <iostream>
#include <cmath>
#define MAX_N 301
using namespace std;
int N;
int Stairs[MAX_N];    // 계단에 쓰여진 점수
int DP[MAX_N];    // 해당 계단까지의 최댓값 저장

void DynamicProgramming() {
    DP[1] = Stairs[1];
    DP[2] = Stairs[1] + Stairs[2];
    DP[3] = max(Stairs[1] + Stairs[3], Stairs[2] + Stairs[3]);

    for (int i=4; i<= N; i++) {
        DP[i] = max(DP[i-2] + Stairs[i], DP[i-3] + Stairs[i-1] + Stairs[i]);
    }

    cout << DP[N] << endl;
}

int main() {
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> Stairs[i];
    }

    DynamicProgramming();
}