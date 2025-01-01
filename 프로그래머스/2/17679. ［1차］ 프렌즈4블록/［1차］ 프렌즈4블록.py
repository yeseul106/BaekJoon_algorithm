from collections import deque
import copy

# 왼쪽 위 좌표를 기준으로 2X2 사각형 탐색
dy = [0, 1, 1]
dx = [1, 0, 1]

tmp_board = [['.'] * 30 for _ in range(30)]
change = [[False] * 30 for _ in range(30)]

def pb(b, m, n):
    for i in range(m):
        for j in range(n):
            print(b[i][j], end=" ")
        print()
    print()

def bfs(y, x, board, m, n):
    global tmp_board
    global change
    cnt = 0
    pos = deque()
    flag = False

    for i in range(3):
        ny = y + dy[i]
        nx = x + dx[i]

        if 0 <= ny < m and 0 <= nx < n and board[y][x] == board[ny][nx]:
            cnt += 1
            pos.append([ny, nx])

    if cnt == 3:
        tmp_board[y][x] = 'X'
        change[y][x] = True
        while pos:
            ny, nx = pos.popleft()
            tmp_board[ny][nx] = 'X'
            change[ny][nx] = True
        flag = True
    
    # pb(tmp_board, m, n)
    # pb(change, m, n)
    return flag 


def down(m, n):
    new_board = [['X'] * n for _ in range(m)]
    global tmp_board
    for c in range(n):
        ret = deque()
        for r in range(m):
            if tmp_board[m - r - 1][c] != 'X':
                ret.append(tmp_board[m - r - 1][c])
        pos_r = m - 1
        while ret:
            new_board[pos_r][c] = ret.popleft()
            pos_r -= 1
    tmp_board = copy.deepcopy(new_board)
    
def check_change(m, n):
    ret = 0
    for i in range(m):
        for j in range(n):
            if change[i][j]:
                ret += 1
    return ret
    

def solution(m, n, board):
    answer = 0
    global tmp_board
    global change

    for i in range(m):
        for j in range(n):
            tmp_board[i][j] = board[i][j]
    # pb(tmp_board, m, n)
    
    while True:
        flag = False
        change = [[False] * n for _ in range(m)]
        board = copy.deepcopy(tmp_board)
        for i in range(m):
            for j in range(n):
                if board[i][j] != 'X':
                    is_change = bfs(i, j, board, m, n)
                    if not flag and is_change:
                        flag = True
        if not flag:
            break
        
        answer += check_change(m, n)
        down(m, n)
    
    return answer