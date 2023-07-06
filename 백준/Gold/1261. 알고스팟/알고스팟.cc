#include<iostream>
#include<string>
#include<queue>

#define MAX 100
#define INF 987654321
using namespace std;
 
int N, M;
int MAP[MAX][MAX];
int Dist[MAX][MAX];
 
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

void Input() {
    cin >> N >> M;

    for(int i=0; i<M; i++) {
        string s;
        cin >> s;
        for (int j=0; j<s.length(); j++) {
            MAP[i][j] = s.at(j) -'0';
            Dist[i][j] = INF;
        }
    }
}

void BFS(int a, int b)
{
    queue<pair<int, int>> Q;
    Q.push(make_pair(a, b));
    Dist[a][b] = 0;
 
    while (!Q.empty())
    {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
            
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
                
            if (nx < 0 || ny < 0 || nx >= M || ny >= N) continue;
            
            if (MAP[nx][ny] == 1)
            {
                if (Dist[nx][ny] > Dist[x][y] + 1)
                {
                    Dist[nx][ny] = Dist[x][y] + 1;
                    Q.push(make_pair(nx, ny));
                }
            }
            else if (MAP[nx][ny] == 0)
            {
                if (Dist[nx][ny] > Dist[x][y])
                {
                    Dist[nx][ny] = Dist[x][y];
                    Q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Input();
    BFS(0,0);

    cout << Dist[M-1][N-1] << endl;

    return 0;
}