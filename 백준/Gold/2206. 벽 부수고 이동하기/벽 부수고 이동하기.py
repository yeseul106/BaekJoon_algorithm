from collections import deque


def pb(b):
    for v in b:
        print(v)
    print()


dy = [-1, 0, 1, 0]
dx = [0, -1, 0, 1]


def bfs(sy, sx):
    global visited
    q = deque()

    q.append([sy, sx, 0])
    visited[sy][sx][0] = 1

    while q:
        y, x, block = q.popleft()
        # pb(new_board)
        # print(change_num)
        # print(y, x, block)
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            # print(ny, nx)
            if 0 <= ny < n and 0 <= nx < m and visited[ny][nx][block] == 987654321:
                if board[ny][nx] == '0':
                    # 그냥 가면 됨
                    q.append([ny, nx, block])
                    visited[ny][nx][block] = visited[y][x][block] + 1
                elif board[ny][nx] == '1':
                    if block == 0:
                        q.append([ny, nx, block + 1])
                        visited[ny][nx][block + 1] = visited[y][x][block] + 1
        # print()


n, m = map(int, input().split())
board = [list(input()) for _ in range(n)]
visited = [[[987654321, 987654321] for _ in range(m)] for _ in range(n)]

# pb(visited)

bfs(0, 0)

# pb(visited)

ret = min(visited[n - 1][m - 1][0], visited[n - 1][m - 1][1])
if ret == 987654321:
    print("-1")
else:
    print(ret)
