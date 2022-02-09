/*
- ����

N��Mũ���� �迭�� ǥ���Ǵ� �̷ΰ� �ִ�.

1   0   1   1   1   1
1   0   1   0   1   0
1   0   1   0   1   1
1   1   1   0   1   1
�̷ο��� 1�� �̵��� �� �ִ� ĭ�� ��Ÿ����, 0�� �̵��� �� ���� ĭ�� ��Ÿ����. �̷��� �̷ΰ� �־����� ��, (1, 1)���� ����Ͽ� (N, M)�� ��ġ�� �̵��� �� ������ �ϴ� �ּ��� ĭ ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
�� ĭ���� �ٸ� ĭ���� �̵��� ��, ���� ������ ĭ���θ� �̵��� �� �ִ�.

���� �������� 15ĭ�� ������ (N, M)�� ��ġ�� �̵��� �� �ִ�. ĭ�� �� ������ ���� ��ġ�� ���� ��ġ�� �����Ѵ�.

- �Է�:
ù° �ٿ� �� ���� N, M(2 �� N, M �� 100)�� �־�����. ���� N���� �ٿ��� M���� ������ �̷ΰ� �־�����. ������ ������ �پ �Է����� �־�����.

- ���:
ù° �ٿ� ������ �ϴ� �ּ��� ĭ ���� ����Ѵ�. �׻� ������ġ�� �̵��� �� �ִ� ��츸 �Է����� �־�����.
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
int dist[100][100] = { 0 }; // ������ ���� �κ�. �� �̵� �Ÿ��� ���ϱ� ���ؼ� ��� !
int visit[100][100] = { 0 };
queue<pair<int, int>> Q;

//������ ��� ����
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

            //�ٿ���� �ȿ� �����ϰ�, ���� �湮���� �ʾҴٸ�
            if ((newx >= 0 && newx < M) && (newy >= 0 && newy < N) && visit[newy][newx] == 0 && map[newy][newx]==1) {
                Q.push(pair<int, int>(newx, newy));
                visit[newy][newx] = 1;
                // ���� ���� + 1
                dist[newy][newx] = dist[w.second][w.first] + 1;
            }
        }

    }
}

int main() {
    scanf("%d %d\n", &N, &M);

    // �̷� �Է� �ޱ�
    for (int i = 0; i < N; i++) {
        string s;
        getline(cin, s);
        for (int j = 0; j < M; j++) {
            int tmp = (s[j] -'0');
            map[i][j] = tmp;
        }
    }


    // �̷� Ž�� �ϱ�
    // ���� BFS ������ ó�� �����¿츦 Ž���ؾ��ҵ�.
    BFS(0, 0);

    printf("%d\n", dist[N-1][M-1]+1);

}