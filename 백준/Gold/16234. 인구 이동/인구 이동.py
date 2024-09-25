from collections import deque

N, L, R = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(N)]

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

ret = 0

def pp(p):
    for v in p:
        print(v)
    print()

def bfs(sy, sx, visited):
    q = deque()
    union_list = [(sy, sx)]  # 시작점 포함
    q.append((sy, sx))
    visited[sy][sx] = True

    num = board[sy][sx]
    cnt = 1

    while q:
        y, x = q.popleft()

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if 0 <= ny < N and 0 <= nx < N and not visited[ny][nx]:
                if L <= abs(board[ny][nx] - board[y][x]) <= R:
                    q.append((ny, nx))
                    visited[ny][nx] = True
                    union_list.append((ny, nx))
                    num += board[ny][nx]
                    cnt += 1

    return union_list, num, cnt

def change_board(unions):
    for union, total, count in unions:
        change_num = total // count
        for y, x in union:
            board[y][x] = change_num

while True:
    visited = [[False] * N for _ in range(N)]
    unions = []
    moved = False

    for i in range(N):
        for j in range(N):
            if not visited[i][j]:
                union_list, total, count = bfs(i, j, visited)
                if count > 1:  # 두 영역 이상 합쳐 졌을 때만 인구 이동
                    unions.append((union_list, total, count))
                    moved = True

    if not moved:  # 인구 이동이 없으면 종료
        break

    change_board(unions)
    ret += 1

print(ret)
