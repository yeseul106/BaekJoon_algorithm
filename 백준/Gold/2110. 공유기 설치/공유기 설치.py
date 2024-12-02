N, C = map(int, input().split())
houses = []
for _ in range(N):
    houses.append(int(input()))

ret = 1
left = 1
right = int(1e9)
houses = sorted(houses)

while left <= right:
    mid = (left + right) // 2

    # mid가 인접한 집 사이의 거리
    # 인접한 두 집 사이의 거리가 mid 일 때, C개를 설치할 수 있니 ?
    total = 1
    before_house = houses[0]
    for i in range(1, len(houses)):
        if (houses[i] - before_house) >= mid:
            total += 1
            before_house = houses[i]

    if total >= C:
        left = mid + 1
        ret = max(ret, mid)
    else:
        right = mid - 1

print(ret)
