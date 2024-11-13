from collections import deque

m, n = map(int, input().split())
map = [list(map(int, input().split())) for _ in range(n)]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

ret = 0
visited = [[False] * m for _ in range(n)]
q = deque()

def bfs():
    global ret
    global visited
    global q

    while q:
        y, x, cnt = q.popleft()
        ret = cnt

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            ncnt = cnt + 1

            if 0 <= ny < n and 0 <= nx < m and map[ny][nx] == 0 and not visited[ny][nx]:
                q.append([ny, nx, ncnt])
                visited[ny][nx] = True

for i in range(n):
    for j in range(m):
        if map[i][j] == 1:
            q.append([i, j, 0])
            visited[i][j] = True

bfs()

is_complete = True
for i in range(n):
    for j in range(m):
        if map[i][j] == 0 and not visited[i][j]:
            is_complete = False

if is_complete:
    print(ret)
else:
    print(-1)