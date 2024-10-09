import math
from collections import deque

# def pb(b):
#     for v in b:
#         print(v)
#     print()

N, M, K = map(int, input().split())
fireballs = [list(map(int, input().split())) for _ in range(M)]

board = [[deque() for _ in range(N)] for _ in range(N)]

dy = [-1, -1, 0, 1, 1, 1, 0, -1]
dx = [0, 1, 1, 1, 0, -1, -1, -1]

# 처음 입력받은 파이어볼 board에 넣기
for list in fireballs:
    y, x, m, s, d = list
    board[y-1][x-1].append([m,s,d])

for _ in range(K):
    # board 돌면서 모든 fireball 움직이기
    new_board = [[deque() for _ in range(N)] for _ in range(N)]
    for y in range(N):
        for x in range(N):
            if len(board[y][x]) != 0:
                # 모든 파이어볼이 자신의 방향 di로 속력 si칸 만큼 이동한다.
                for m, s, d in board[y][x]:
                    ny = (y + dy[d] * s) % N
                    nx = (x + dx[d] * s) % N
                    new_board[ny][nx].append([m,s,d])

    # 2개 이상의 파이어볼이 있는 경우
    for y in range(N):
        for x in range(N):
            if len(new_board[y][x]) >= 2:
                # 파이어볼 합치기
                total_m, total_s, total_d = 0, 0, []
                ball_cnt = len(new_board[y][x])
                odd_num, even_num = 0, 0

                for m, s, d in new_board[y][x]:
                    total_m += m
                    total_s += s
                    if d % 2 == 0:
                        even_num += 1
                    else:
                        odd_num += 1

                # 탐색 종료하면 무조건 clear
                new_board[y][x].clear()

                # 나누어진 파이어볼의 질량, 속력, 방향은 다음과 같다.
                # 질량은 ⌊(합쳐진 파이어볼 질량의 합)/5⌋이다.
                # 속력은 ⌊(합쳐진 파이어볼 속력의 합)/(합쳐진 파이어볼의 개수)⌋이다.

                total_m = math.floor(total_m/5)
                total_s = math.floor(total_s/ball_cnt)
                # 합쳐지는 파이어볼의 방향이 모두 홀수이거나 모두 짝수이면, 방향은 0, 2, 4, 6이 되고, 그렇지 않으면 1, 3, 5, 7이 된다.
                if odd_num == ball_cnt or even_num == ball_cnt:
                    total_d = [0, 2, 4, 6]
                else:
                    total_d = [1, 3, 5, 7]

                if total_m == 0:
                    continue

                for i in range(4):
                    new_board[y][x].append([total_m, total_s, total_d[i]])

    board = new_board

ret = 0
for y in range(N):
    for x in range(N):
        if len(board[y][x]) != 0:
            for m, s, d in board[y][x]:
                ret += m
print(ret)