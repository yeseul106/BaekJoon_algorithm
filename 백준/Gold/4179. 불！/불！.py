from collections import deque

R, C = map(int, input().split())
board = [list(input()) for _ in range(R)]
time_board = [[int(1e9)]*C for _ in range(R)]
# go_board = [[-1]*C for _ in range(R)]

dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]

possible = False
ret = 0

j_pos = []
f_pos = []


def pp(p):
    for v in p:
        print(v)
    print()


def get_pos():
    for r in range(R):
        for c in range(C):
            if board[r][c] == "J":
                j_pos.append([r, c])
            if board[r][c] == "F":
                f_pos.append([r, c]) # 불은 여러 개일 수 있음

def move_fire():
    visited = [[False] * C for _ in range(R)]
    q = deque()

    for pos in f_pos:
        sy, sx = pos
        q.append([sy, sx, 0])
        visited[sy][sx] = True

    while q:
        y, x, cnt = q.popleft()
        time_board[y][x] = cnt

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            ncnt = cnt + 1

            if (0 <= ny < R and 0 <= nx < C and board[ny][nx] != "#" and not visited[ny][nx]):
                visited[ny][nx] = True
                q.append([ny, nx, ncnt])

def move_jihun():
    global ret
    global possible

    visited = [[False] * C for _ in range(R)]
    sy, sx = j_pos[0]
    q = deque()

    q.append([sy, sx, 0])
    visited[sy][sx] = True

    while q:
        y, x, time = q.popleft()

        # go_board[y][x] = time

        if x == 0 or x == C-1 or y == 0 or y == R-1:
            possible = True
            ret = time
            return

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            ntime = time + 1

            if (0 <= ny < R and 0 <= nx < C and board[ny][nx] == "." and not visited[ny][nx] and time_board[ny][nx] > ntime):
                q.append([ny, nx, ntime])
                visited[ny][nx] = True


get_pos()
move_fire()
# pp(time_board)
move_jihun()
# pp(go_board)
if possible:
    print(ret+1)
else:
    print("IMPOSSIBLE")


