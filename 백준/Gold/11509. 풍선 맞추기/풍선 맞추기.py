n = int(input())
arr = list(map(int, input().split()))
balloon = [0] * (int(1e6) + 4)
ret = 0

for i in range(n):
    now_h = arr[i]
    # 내 앞에 나보다 높이가 1 큰 풍선 있는지 확인
    if balloon[now_h + 1] > 0:
        balloon[now_h + 1] -= 1
    else:
        ret += 1
    balloon[now_h] += 1

print(ret)
