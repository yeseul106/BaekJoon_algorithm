from itertools import combinations

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]


def find_close_chicken(house, chickens):
    min_dist = int(1e9)
    for chicken in chickens:
        min_dist = min(min_dist, abs(house[0] - chicken[0]) + abs(house[1] - chicken[1]))
    return min_dist

# 일단 집 위치들이랑 치킨집 위치들 다 모아두기
house_pos = []
chicken_pos = []
for i in range(n):
    for j in range(n):
        if board[i][j] == 1:
            house_pos.append([i, j])
        if board[i][j] == 2:
            chicken_pos.append([i, j])

# 치킨 집들 중에서 m개 뽑기
pick_chicken_idx = []
for num in range(1, m + 1):
    for i in combinations(chicken_pos, num):
        pick_chicken_idx.append(i)

# print(pick_chicken_idx)
ret = int(1e9)

for chickens in pick_chicken_idx:
    sum_dist = 0
    for house in house_pos:
        # 집부터 각각 치킨집까지 bfs로 최단거리 구하기
        sum_dist += find_close_chicken(house, chickens)
    ret = min(ret, sum_dist)

print(ret)