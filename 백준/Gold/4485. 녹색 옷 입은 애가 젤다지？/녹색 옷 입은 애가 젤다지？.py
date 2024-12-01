import heapq

dy = [-1, 0, 1, 0]
dx = [0, -1, 0, 1]
tc = 1

while True:
    N = int(input())
    if N == 0:
        break
    board = [list(map(int, input().split())) for _ in range(N)]
    visited = [[int(1e9)] * N for _ in range(N)]
    q = []
    visited[0][0] = board[0][0]
    heapq.heappush(q, [visited[0][0], 0, 0])

    while q:
        cnt, y, x = heapq.heappop(q)

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if 0 <= ny < N and 0 <= nx < N:
                ncnt = cnt + board[ny][nx]

                if ncnt < visited[ny][nx]:
                    visited[ny][nx] = ncnt
                    heapq.heappush(q, [ncnt, ny, nx])

    print("Problem " + str(tc) + ": " + str(visited[N - 1][N - 1]))
    tc += 1
