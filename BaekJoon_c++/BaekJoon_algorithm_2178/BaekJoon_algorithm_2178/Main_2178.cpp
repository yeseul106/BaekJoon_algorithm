/*
- 문제

N×M크기의 배열로 표현되는 미로가 있다.

1   0   1   1   1   1
1   0   1   0   1   0
1   0   1   0   1   1
1   1   1   0   1   1
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오.
한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

- 입력:
첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

- 출력:
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.
*/

#include <iostream>
#include <queue>
#include <utility>
#include <cstdio>
#include <string>
#pragma warning (disable:4996)
using namespace std;

int cnt = 0;
int N, M;
int map[100][100];
int dist[100][100] = { 0 }; // 생각지 못한 부분. 총 이동 거리를 구하기 위해서 사용 !
int visit[100][100] = { 0 };
queue<pair<int, int>> Q;

//인접한 노드 접근
int x_arr[4] = { 0, -1, 1, 0 };
int y_arr[4] = { -1, 0, 0, 1 };


void BFS(int x, int y) {
    visit[y][x] = 1;
    Q.push(pair<int, int>(x, y));

    while (!Q.empty()) {
        pair<int, int> w = Q.front();
        Q.pop();
        cnt++;

        for (int i = 0; i < 4; i++) {
            pair<int, int> now = make_pair(x_arr[i], y_arr[i]);
            int newx = w.first + now.first;
            int newy = w.second + now.second;

            //바운더리 안에 존재하고, 아직 방문하지 않았다면
            if ((newx >= 0 && newx < M) && (newy >= 0 && newy < N) && visit[newy][newx] == 0 && map[newy][newx]==1) {
                Q.push(pair<int, int>(newx, newy));
                visit[newy][newx] = 1;
                // 이전 순서 + 1
                dist[newy][newx] = dist[w.second][w.first] + 1;
            }
        }

    }
}

int main() {
    scanf("%d %d\n", &N, &M);

    // 미로 입력 받기
    for (int i = 0; i < N; i++) {
        string s;
        getline(cin, s);
        for (int j = 0; j < M; j++) {
            int tmp = (s[j] -'0');
            map[i][j] = tmp;
        }
    }


    // 미로 탐색 하기
    // 기존 BFS 문제들 처럼 상하좌우를 탐색해야할듯.
    BFS(0, 0);

    printf("%d\n", dist[N-1][M-1]+1);

}