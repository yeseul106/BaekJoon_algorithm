#include <iostream>
#include <vector>
#include <functional>
#include <queue>
using namespace std;

const int MAX =1000001;
bool visited[MAX];


int minSecond(int N, int K) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    //경과 시간을 기준으로 우선순위 큐(짧을수록 우선순위 크다)
    q.push(make_pair(0, N));
    visited[N] = true;

    while (!q.empty()) {
        int nowSecond = q.top().first;
        int nowLocation = q.top().second;

        q.pop();
        if (nowLocation == K) //목적지 도달 시 break
            return nowSecond;
        //세 가지 경우의 수

        //이미 방문한 지점은 큐에 넣지 않는다
        if (nowLocation * 2 < MAX && !visited[nowLocation * 2]) {
        q.push(make_pair(nowSecond, nowLocation * 2)); //순간이동하는데 걸리는 시간 0초
        visited[nowLocation * 2] = true;
        }

        if (nowLocation + 1 < MAX && !visited[nowLocation + 1]) {
        q.push(make_pair(nowSecond + 1, nowLocation + 1));
        visited[nowLocation + 1] = true;
        }

        if (nowLocation - 1 >= 0 && !visited[nowLocation - 1]) {
        q.push(make_pair(nowSecond + 1, nowLocation - 1));
        visited[nowLocation - 1] = true;
        }
    }
}

 
int main(void) {
    int N, K;
    cin >> N >> K;

    cout << minSecond(N, K) << "\n";
    return 0;
}