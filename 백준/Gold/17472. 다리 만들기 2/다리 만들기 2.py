from collections import deque

dy = [-1, 0, 1, 0]
dx = [0, -1, 0, 1]


def pb(b):
    for v in b:
        print(v)
    print()


def union(a, b):
    global parent
    rootA = find(a)
    rootB = find(b)

    parent[rootA] = rootB


def find(a):
    global parent
    if parent[a] == a:
        return a

    parent[a] = find(parent[a])

    return parent[a]


def fill_land(sy, sx, land_num):
    global visited
    global board
    q = deque()
    visited[sy][sx] = True
    board[sy][sx] = land_num
    q.append([sy, sx])

    while q:
        y, x = q.popleft()

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if 0 <= ny < n and 0 <= nx < m and not visited[ny][nx] and board[ny][nx] != 0:
                board[ny][nx] = land_num
                visited[ny][nx] = True
                q.append([ny, nx])


def make_bridge(sy, sx):
    global bridge
    q = deque()

    # 한 방향으로만 가야하므로
    q.append([sy, sx, 0, 0])  # y, x, dir, cnt
    q.append([sy, sx, 1, 0])
    q.append([sy, sx, 2, 0])
    q.append([sy, sx, 3, 0])

    while q:
        y, x, dir, cnt = q.popleft()

        ny = y + dy[dir]
        nx = x + dx[dir]
        ncnt = cnt + 1

        if 0 <= ny < n and 0 <= nx < m and board[ny][nx] != board[sy][sx] and board[ny][nx] >= 1 and cnt >= 2:
            bridge.add((min(board[ny][nx], board[sy][sx]), max(board[ny][nx], board[sy][sx]), cnt))

        if 0 <= ny < n and 0 <= nx < m and board[ny][nx] == 0:
            q.append([ny, nx, dir, ncnt])


n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
visited = [[False] * m for _ in range(n)]

land_num = 0
for i in range(n):
    for j in range(m):
        if not visited[i][j] and board[i][j] != 0:
            land_num += 1
            fill_land(i, j, land_num)


# pb(board)
bridge = set()

for i in range(n):
    for j in range(m):
        if board[i][j] >= 1:  # 섬이면
            make_bridge(i, j)

# MST 만들기
bridge = list(bridge)
bridge.sort(key=lambda x: x[2])

# print(bridge)

parent = [i for i in range(land_num + 1)]
ret = 0
cnt = 0

for edge in bridge:
    a, b, w = edge

    if find(a) != find(b):
        ret += w
        union(a, b)
        cnt += 1

if cnt == (land_num - 1):
    print(ret)
else:
    print(-1)
