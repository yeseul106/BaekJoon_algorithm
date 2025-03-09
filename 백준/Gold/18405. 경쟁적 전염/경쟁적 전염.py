from collections import deque

def pb(b):
    for v in b:
        print(v)
    print()

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

n, k = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
s, input_y, input_x = map(int, input().split())
q = deque()
visited = [[-1] * n for _ in range(n)]

for i in range(n):
    for j in range(n):
        if board[i][j] != 0:
            visited[i][j] = 0
            q.append([i, j, 0])

while q:
    y, x, time = q.popleft()
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        ntime = time + 1

        if ntime > s:
            break

        if 0 <= ny < n and 0 <= nx < n:
            if board[ny][nx] == 0 and visited[ny][nx] <= 0:
                visited[ny][nx] = ntime
                board[ny][nx] = board[y][x]
                q.append([ny, nx, ntime])
            elif board[ny][nx] != 0 and visited[ny][nx] == ntime:
                if board[ny][nx] > board[y][x]:
                    board[ny][nx] = board[y][x]
                    q.append([ny, nx, ntime])

print(board[input_y -1 ][input_x -1])
