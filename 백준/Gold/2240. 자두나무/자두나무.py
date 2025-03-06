t, w = map(int, input().split())
plum_arr = [0]
dp = [[0] * (w + 1) for _ in range(t + 1)]

for _ in range(t):
    plum_arr.append(int(input()))

for time in range(t + 1):
    # 1번 나무에서 안움직임
    if plum_arr[time] == 1:
        dp[time][0] = dp[time-1][0] + 1
    else:
        dp[time][0] = dp[time-1][0]

    for move in range(1, w+1):
        if (plum_arr[time] == 1 and move % 2 == 0):
            dp[time][move] = max(dp[time-1][move], dp[time-1][move-1]) + 1
        elif (plum_arr[time] == 2 and move % 2 == 1):
            dp[time][move] = max(dp[time-1][move], dp[time-1][move-1]) + 1
        else:
            dp[time][move] = max(dp[time-1][move], dp[time-1][move-1])

ret = 0
for num in dp[t]:
    ret = max(ret, num)
print(ret)