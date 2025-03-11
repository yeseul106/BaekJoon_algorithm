from collections import deque

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

def pb(b):
    for v in b:
        print(v)
    print()

def fork_bfs(sy, sx, n, m, storage, board, request, round_num, visited):
    q = deque()
    q.append([sy, sx])
    visited[sy][sx] = True
    
    # print("sy, sx : ", sy, sx)
    
    while q:
        y, x = q.popleft()
        # print("y, x : ", y, x)
        
        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]
            # print("ny, nx : ", ny, nx)
            # print("round_num : ", round_num)
            
            if 0 <= ny < n and 0 <= nx < m and not visited[ny][nx]:
                visited[ny][nx] = True
                # print("board[ny][nx] : ", board[ny][nx])
                
                if 0 < board[ny][nx] < round_num:
                    q.append([ny, nx])
                elif board[ny][nx] == 0 and storage[ny][nx] == request:
                    board[ny][nx] = round_num

def fork(n, m, storage, board, request, round_num):
    # 가장 자리만 일단 보기
    visited = [[False] * m for _ in range(n)]
    # 모서리
    pos_arr = [[0,0], [0, m-1], [n-1, 0], [n-1, m-1]]
    
    for pos in pos_arr:
        y,x = pos
        if board[y][x] == 0 and storage[y][x] == request:
            board[y][x] = round_num
        elif 0 < board[y][x] < round_num:
            fork_bfs(y, x, n, m, storage, board, request, round_num, visited) 
    
    # 왼쪽 가장자리
    for i in range(1, n):
        if board[i][0] == 0 and storage[i][0] == request:
            board[i][0] = round_num
        elif 0 < board[i][0] < round_num:
            fork_bfs(i, 0, n, m, storage, board, request, round_num, visited)
            
    # 오른쪽 가장자리
    for i in range(1, n):
        if board[i][m - 1] == 0 and storage[i][m - 1] == request:
            board[i][m - 1] = round_num
        elif 0 < board[i][m - 1] < round_num:
            fork_bfs(i, m - 1, n, m, storage, board, request, round_num, visited)
    
    # 위쪽 가장자리
    for i in range(1, m):
        if board[0][i] == 0 and storage[0][i] == request:
            board[0][i] = round_num
        elif 0 < board[0][i] < round_num:
            fork_bfs(0, i, n, m, storage, board, request, round_num, visited)
            
    # 아래쪽 가장자리
    for i in range(1, m):
        if board[n - 1][i] == 0 and storage[n - 1][i] == request:
            board[n - 1][i] = round_num
        elif 0 < board[n - 1][i] < round_num:
            fork_bfs(n - 1, i, n, m, storage, board, request, round_num, visited)
            
def crain(n, m, storage, board, request, round_num):
    for i in range(n):
        for j in range(m):
            if board[i][j] == 0 and storage[i][j] == request:
                board[i][j] = round_num

def solution(storage, requests):
    answer = 0
    n = len(storage)
    m = len(storage[0])
    board = [[0] * m for _ in range(n)]
    
    for idx, request in enumerate(requests):
        if len(request) == 1:
            fork(n, m, storage, board, request, idx + 1)
        else:
            crain(n, m, storage, board, request[0], idx + 1)
    
    for i in range(n):
        for j in range(m):
            if board[i][j] == 0:
                answer += 1
    
    return answer