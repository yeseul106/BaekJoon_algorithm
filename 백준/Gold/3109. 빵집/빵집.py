def pb(b):
    for v in b:
        print(v)
    print()

def dfs(y, x):
    global visited
    global ret
    global is_done

    if is_done:
        return

    if x == c - 1:
        ret += 1
        # pb(visited)
        is_done = True
        return

    for i in range(3):
        ny = y + dy[i]
        nx = x + 1

        if 0 <= ny < r and 0 <= nx < c and visited[ny][nx] != 1 and board[ny][nx] == '.' and not is_done:
            visited[ny][nx] = 1
            dfs(ny, nx)

dy = [-1, 0, 1]

r, c = map(int, input().split())
board = [list(input()) for _ in range(r)]
visited = [[0] * c for _ in range(r)]
ret = 0

for i in range(r):
    visited[i][0] = 1
    is_done = False
    dfs(i, 0)
    # pb(visited)

print(ret)
