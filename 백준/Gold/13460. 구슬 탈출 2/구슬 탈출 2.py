from collections import deque

n, m = map(int, input().split())
board = [input() for _ in range(n)]

dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]
cnt = 0

def get_pos():
    ry, rx, by, bx = 0, 0, 0, 0
    for i in range(n):
        for j in range(m):
            if board[i][j] == "R":
                rx, ry = i, j
            if board[i][j] == "B":
                bx, by = i, j

    return rx, ry, bx, by

def roll_ball(x,y, dx, dy):
    cnt = 0
    # 한번 기울이면 벽을 만나거나, 구멍에 빠지지 않을 때까지 공이 굴러감
    while board[x+dx][y+dy]!="#" and board[x][y]!="O":
        x+=dx
        y+=dy
        cnt+=1
    return x, y, cnt


def bfs():
    rx, ry, bx, by = get_pos()

    q = deque()
    q.append((rx, ry, bx, by, 1))

    while q:
        rx, ry, bx, by, result = q.popleft()

        if result > 10:
            break

        for i in range(4):
            nrx, nry, rcnt = roll_ball(rx, ry, dx[i], dy[i])
            nbx, nby, bcnt = roll_ball(bx, by, dx[i], dy[i])

            # 파란 구슬이 구멍에 들어갈 경우
            if board[nbx][nby] == "O":
                continue

            # 빨간 구슬이 들어갈 경우 성공
            if board[nrx][nry] == "O":
                print(result)
                return

            # 둘이 겹쳐있을경우 더 많이 이동한녀석을 1칸 뒤로 보낸다.
            if nrx == nbx and nry == nby:
                if rcnt > bcnt:
                    nrx -= dx[i]
                    nry -= dy[i]
                else:
                    nbx -= dx[i]
                    nby -= dy[i]

            q.append((nrx, nry, nbx, nby, result + 1))
    print(-1)

bfs()

