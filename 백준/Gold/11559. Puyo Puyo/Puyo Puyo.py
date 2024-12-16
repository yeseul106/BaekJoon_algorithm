from collections import deque

dy = [-1, 0, 1, 0]
dx = [0, -1, 0, 1]


def pb(b):
    for v in b:
        print(v)
    print()


def bfs(sy, sx):
    global visited
    global board
    global ret
    global flag
    q = deque()
    visited[sy][sx] = True
    list = []
    list.append([sy, sx])
    q.append([sy, sx, list])

    while q:
        y, x, list = q.popleft()

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if 0 <= ny < 12 and 0 <= nx < 6 and not visited[ny][nx] and board[y][x] == board[ny][nx]:
                list.append([ny, nx])
                q.append([ny, nx, list])
                visited[ny][nx] = True

    if len(list) >= 4:
        flag = True
        for y, x in list:
            board[y][x] = '.'


def down():
    global board
    for c in range(6):
        cnt = 0
        q = []

        for r in range(12):
            if board[r][c] == '.':
                cnt += 1
            else:
                q.append(board[r][c])

        # 보드에 채우기
        idx = 11
        while q:
            board[idx][c] = q.pop()
            idx -= 1
        while idx >= 0:
            board[idx][c] = '.'
            idx -= 1


board = [list(input()) for _ in range(12)]

# pb(board)

# bfs 터뜨리기
ret = 0

while True:
    flag = False
    visited = [[False] * 6 for _ in range(12)]
    for i in range(12):
        for j in range(6):
            if not visited[i][j] and board[i][j] != '.':
                bfs(i, j)
    if flag:
        ret += 1
        down()
    else:
        break

print(ret)