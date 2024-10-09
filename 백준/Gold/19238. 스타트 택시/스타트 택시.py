from collections import deque

N, M, taxi_energy = map(int, input().split())
map_info = [list(map(int, input().split())) for _ in range(N)] # 진짜 지도 -> 사람 2
board = [[deque() for _ in range(N)] for _ in range(N)]
taxi_y, taxi_x = map(int, input().split())
taxi_y -= 1
taxi_x -= 1

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]

person_info = [list(map(int, input().split())) for _ in range(M)]

def pb(b):
    for v in b:
        print(v)
    print()

def BFS(sy, sx):
    queue = deque()
    visited = [[False] * N for _ in range(N)]
    distance = [[-1] * N for _ in range(N)]

    queue.append([sy, sx, 0])

    while queue:
        y, x, cnt = queue.popleft()
        visited[y][x] = True
        distance[y][x] = cnt
        cnt += 1

        for i in range(4):
            ny = y + dy[i]
            nx = x + dx[i]

            if 0 <= ny < N and 0 <= nx < N and not visited[ny][nx] and map_info[ny][nx] != 1:
                queue.append([ny, nx, cnt])
                visited[ny][nx] = True

    return distance

# 보드에 승객 정보 넣기
for person in person_info:
    now_y, now_x, finish_y, finish_x = person
    map_info[now_y-1][now_x-1] = 2
    board[now_y-1][now_x-1].append([finish_y-1, finish_x-1])

# pb(map_info)
# pb(board)

remind_person = M
remind_taxi_energy = taxi_energy
finish_flag = False

# 연료가 있을 동안 반복
while remind_taxi_energy >= 0:
    # 모든 손님 이동 완료
    if remind_person == 0:
        finish_flag = True
        break

    # 가장 가까운 손님 태우기
    distance_board = BFS(taxi_y, taxi_x)
    # print("=======")
    # print("taxi_y, taxi_x", taxi_y, taxi_x)
    # pb(distance_board)
    min_distance = int(1e9)
    pick_person_info = []

    for i in range(N):
        for j in range(N):
            if map_info[i][j] == 2:
                if min_distance > distance_board[i][j]:
                    # 태울 손님 정보 업데이트
                    pick_person_info = [i, j, distance_board[i][j]]
                    min_distance = distance_board[i][j]

    # 택시랑 승객 위치 같음
    to_go_y, to_go_x, dist = pick_person_info
    # print("to_go_y, to_go_x, dist" , to_go_y, to_go_x, dist)

    # 갈 수 있는 승객이 없음
    if min_distance == int(1e9):
        break

    if min_distance == -1:
        break

    # 택시 연료 부족하면 종료해야함
    if remind_taxi_energy < dist:
        remind_taxi_energy -= dist
        continue

    # 연료 써서 가기
    remind_taxi_energy -= dist
    taxi_y, taxi_x = to_go_y, to_go_x
    map_info[to_go_y][to_go_x] = 0
    # print("go remind_taxi_energy:" ,remind_taxi_energy)

    # 해당 승객의 목적지 좌표
    finish_y, finish_x = board[to_go_y][to_go_x][0]
    # print("finish_y, finish_x", finish_y, finish_x)
    board[to_go_y][to_go_x].clear()

    # 목적지까지의 최단거리 또 구해야함
    finish_distance_board = BFS(taxi_y, taxi_x)
    finish_distance = finish_distance_board[finish_y][finish_x]
    # print("finish_distance" , finish_distance)

    # 목적지까지 갈 수 있는지 판단
    if remind_taxi_energy < finish_distance:
        remind_taxi_energy -= finish_distance
        continue
    if finish_distance == -1:
        break

    remind_taxi_energy -= finish_distance
    # print("finish remind_taxi_energy", remind_taxi_energy)
    taxi_y, taxi_x = finish_y, finish_x
    remind_taxi_energy += (finish_distance * 2)
    # print("charge remind_taxi_energy", remind_taxi_energy)
    remind_person -= 1
    # print("remind_person", remind_person)

if finish_flag:
    print(remind_taxi_energy)
else:
    print(-1)