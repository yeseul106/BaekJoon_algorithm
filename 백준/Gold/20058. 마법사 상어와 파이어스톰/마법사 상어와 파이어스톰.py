from collections import deque

N, Q = map(int, input().split())
board_size = 2 ** N

board = [list(map(int, input().split())) for _ in range(board_size)]
step_list = list(map(int, input().split()))
visited = [[False] * board_size for _ in range(board_size)]

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def pb(p):
    for v in (p):
        print(v)
    print()

def BFS(sy, sx):
    queue = deque()
    cnt = 0

    queue.append([sy, sx])
    visited[sy][sx] = True

    while queue:
        y, x = queue.popleft()
        cnt += 1

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if 0 <= ny < board_size and 0 <= nx < board_size and not visited[ny][nx] and board[ny][nx] != 0:
                queue.append([ny, nx])
                visited[ny][nx] = True
    return cnt


# 단계 L 결정
for L in step_list:
    turn_board = [[0] * board_size for _ in range(board_size)]
    melt_board = [[0] * board_size for _ in range(board_size)]
    divide_size = 2 ** L
    # 격자 크기마다 회전
    cnt = 0
    for y in range(0, board_size, divide_size):
        for x in range(0, board_size, divide_size):
            for i in range(divide_size):
                for j in range(divide_size):
                    turn_board[i + y][j + x] = board[divide_size - 1 - j + y][i + x]


    # 이후 얼음이 있는 칸 중 상하좌우에서 얼음 2개 이하면 -1
    for y in range(board_size):
        for x in range(board_size):
            ice_cnt = 0

            for i in range(4):
                ny = y + dy[i]
                nx = x + dx[i]

                if 0 <= ny < board_size and 0 <= nx < board_size:
                    if turn_board[ny][nx] != 0:
                        ice_cnt += 1

            if ice_cnt <= 2 and turn_board[y][x] > 0:
                melt_board[y][x] = turn_board[y][x] - 1
            else:
                melt_board[y][x] = turn_board[y][x]
    board = melt_board


# 다음 2가지 구하기
# 1. 남아있는 얼음 A[r][c]의 합
# 2. 남아있는 얼음 중 가장 큰 덩어리가 차지하는 칸의 개수
# BFS 돌리기

total = 0
ret = 0

for i in range(board_size):
    for j in range(board_size):
        if board[i][j] != 0:
            if not visited[i][j]:
                num = BFS(i, j)
                ret = max(ret, num)
            total += board[i][j]
print(total)
print(ret)