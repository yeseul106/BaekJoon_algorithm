from collections import deque

n = int(input())
board = [list(map(int, input().split())) for _ in range(n)]
shark_size = 2

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def pp(p):
    for v in p:
        print(v)
    print()


def find_shark_pos():
    for i in range(n):
        for j in range(n):
            if board[i][j] == 9:
                board[i][j] = 0 # 아기 상어 움직일 꺼니까 초기화
                return list([i, j])

def bfs(sy, sx):
    y, x = sy, sx
    queue = deque()
    visited = [[False] * n for _ in range(n)]
    distance = [[-1] * n for _ in range(n)]
    time = 0

    queue.append([y, x, 0])
    visited[y][x] = True
    distance[y][x] = 0

    while queue:
        y, x, cnt = queue.popleft()
        time += 1
        cnt += 1

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if 0 <= ny < n and 0 <= nx < n and not visited[ny][nx] and board[ny][nx] <= shark_size:
                queue.append([ny, nx, cnt])
                distance[ny][nx] = cnt
                visited[ny][nx] = True

    return distance

# distance 배열 보고 먹을 물고기 정하기
def find_fish(distance):
    y, x = 0, 0
    min_dist = int(1e9)

    # 왼쪽 맨 위에가 제일 우선 순위가 높기 때문에 거기부터 for문 돌기
    for i in range(n):
        for j in range(n):
             if -1 < distance[i][j] < min_dist and 0 < board[i][j] < shark_size:
                 y , x = i, j
                 min_dist = distance[i][j]

    return y, x, min_dist

ret = 0
eat_fish_num = 0
shark_pos = find_shark_pos()
shark_y = shark_pos[0]
shark_x = shark_pos[1]

while True:
    # 현재 상어 위치에서 먹을 물고기 구하기
    search_result = bfs(shark_y, shark_x)
    #pp(search_result)
    fish_info = find_fish(search_result)

    if fish_info[2] == int(1e9):
        print(ret)
        break
    else:
        shark_y = fish_info[0]
        shark_x = fish_info[1]
        ret += fish_info[2]

        # 물고기 먹기
        board[fish_info[0]][fish_info[1]] = 0
        eat_fish_num += 1

        if eat_fish_num == shark_size:
            shark_size += 1
            eat_fish_num = 0