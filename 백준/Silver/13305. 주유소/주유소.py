n = int(input())
dist_arr = list(map(int, input().split()))
fee_arr = list(map(int, input().split()))

cost = int(1e9)
ret = 0

for i in range(n - 1):
    cost = min(cost, fee_arr[i])
    ret += cost * dist_arr[i]

print(ret)
