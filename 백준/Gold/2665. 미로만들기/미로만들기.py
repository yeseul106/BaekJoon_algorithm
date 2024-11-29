import heapq

N = int(input())
board = [list(input()) for _ in range(N)]
q = []
visited = [[int(1e9)] * N for _ in range(N)]

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]

def pb(b):
    for v in b:
        print(v)
    print()

heapq.heappush(q, [0, 0, 0])

while q:
    black_cnt, y, x = heapq.heappop(q)
    # print("black_cnt, y, x : ", black_cnt, y, x)

    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        ncnt = black_cnt

        if 0 <= ny < N and 0 <= nx < N:
            if board[ny][nx] == '0':
                ncnt += 1
                # print(ny, nx)

            if visited[ny][nx] > ncnt:
                visited[ny][nx] = ncnt
                heapq.heappush(q, [ncnt, ny, nx])

# pb(visited)

print(visited[N-1][N-1])