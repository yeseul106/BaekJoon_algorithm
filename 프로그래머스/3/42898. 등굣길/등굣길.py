def pb(b):
    for v in b:
        print(v)
    print()

def solution(m, n, puddles):
    answer = 0
    dist = [[0] * (m + 1) for _ in range(n + 1)]
    board = [[0] * (m + 1) for _ in range(n + 1)]
    
    for puddle in puddles:
        board[puddle[1]][puddle[0]] = 1
        
    dist[1][1] = 1
        
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            if i == 1 and j == 1:
                continue
            # 왼쪽에서 오는 경우
            if 1 <= j - 1 < m and board[i][j-1] == 0:
                dist[i][j] += dist[i][j-1]
            # 위에서 오는 경우
            if 1 <= i - 1 < n and board[i-1][j] == 0:
                dist[i][j] += dist[i-1][j]
    
    return dist[n][m] % 1000000007