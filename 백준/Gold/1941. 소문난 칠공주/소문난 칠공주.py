from collections import deque
from itertools import combinations

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

def pb(b):
    for v in b:
        print(v)
    print()

def bfs(new_board, sy, sx):
    visited = [[False] * 5 for _ in range(5)]
    som_cnt, cnt = 0, 1
    q = deque()
    q.append([sy, sx])
    if new_board[sy][sx] == 'S':
        som_cnt += 1
    visited[sy][sx] = True

    while q:
        y, x = q.popleft()

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if 0 <= ny < 5 and 0 <= nx < 5 and not visited[ny][nx] and new_board[ny][nx] != '.':
                if new_board[ny][nx] == 'S':
                    som_cnt += 1
                q.append([ny, nx])
                visited[ny][nx] = True
                cnt += 1

    return [cnt, som_cnt]

board = [list(input()) for _ in range(5)]
ret = 0

# 조합을 만들자..? 7개 좌표 구하기 ?
comb = list(combinations(range(25), 7))

for idxs in comb:
    new_board = [['.'] * 5 for _ in range(5)]
    sy, sx = 0, 0
    for idx in idxs:
        y = idx // 5
        x = idx % 5
        sy, sx = y, x
        new_board[y][x] = board[y][x]
    cnt, som_cnt = bfs(new_board, sy, sx)
    if cnt == 7 and som_cnt >= 4:
        ret += 1
print(ret)
