from collections import deque

n = int(input())
dist_arr = deque(list(map(int, input().split())))
fee_arr = deque(list(map(int, input().split())))

total_dist = sum(dist_arr)
dp = [int(1e9) * int(1e9)] * (total_dist + 1)

before_fee = fee_arr.popleft()
dp[0] = 0
to_city_dist = dist_arr.popleft()

for i in range(1, total_dist + 1):
    if to_city_dist != 0:
        dp[i] = dp[i - 1] + before_fee
        to_city_dist -= 1
    else:  # 도시 도착
        now_fee = fee_arr.popleft()
        if (dp[i - 1] + before_fee) >= (dp[i - 1] + now_fee):
            dp[i] = dp[i - 1] + now_fee
            before_fee = now_fee
        else:
            dp[i] = dp[i - 1] + before_fee
        to_city_dist = dist_arr.popleft() - 1
    # print(i, to_city_dist)

# print(dp)
print(dp[total_dist])

