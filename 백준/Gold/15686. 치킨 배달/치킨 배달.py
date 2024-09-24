from itertools import combinations

n, m = map(int, input().split())
map = [list(map(int,input().split())) for _ in range(n)]
chicken_pos = []
list_subset = []

dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]

result = 987654321

# 치킨 집 위치 구하기
def find_chicken():
    for i in range(n):
        for j in range(n):
            if map[i][j] == 2:
                chicken_pos.append([i, j])

# m개 치킨집 선택 -> 부분 집합
def make_subset():

    # 1개부터 M개까지의 모든 조합을 구한다
    for size in range(1, m + 1):
        # combinations를 사용해 부분집합을 구함
        for comb in combinations(chicken_pos, size):
            list_subset.append(list(comb))  # 각 조합을 리스트로 변환하여 추가
    # 결과 출력
    # print(result)

# 각 치킨집과 거리 구해서 최솟값들 더하기
def bfs():
    global result
    for subset in list_subset:
        cityDistance = 0
        for i in range(n):
            for j in range(n):
                if map[i][j] == 1:
                    x, y = i, j
                    distance = 987654321
                    for s in subset:
                        distance = min(distance, abs(x-s[0]) + abs(y-s[1]))
                    cityDistance += distance
        result = min(result, cityDistance)

find_chicken()
make_subset()
bfs()

print(result)