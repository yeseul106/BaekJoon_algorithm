N, M = map(int, input().split())
input_list = [int(input()) for _ in range(N)]

# 정렬
sort_list = sorted(input_list)

hi = 0
ret = sort_list[-1] - sort_list[0]
for lo in range(N):
    while hi < N and (sort_list[hi] - sort_list[lo]) < M:
        hi += 1

    # print("lo : ", lo, "/ hi : ", hi)

    if hi < N and sort_list[hi] - sort_list[lo] >= M:
        ret = min(ret, sort_list[hi] - sort_list[lo])

print(ret)