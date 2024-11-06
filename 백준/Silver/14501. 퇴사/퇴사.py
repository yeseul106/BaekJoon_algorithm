n = int(input())
input_arr = [list(map(int, input().split())) for _ in range(n)]

dp = [0] * (n + 2)

for i in range(1, n + 1):
    dp[i] = max(dp[i], dp[i - 1])
    day, pay = input_arr[i - 1]
    if i + day <= n + 1:
        dp[i + day] = max(dp[i + day], dp[i] + pay)

dp[n + 1] = max(dp[n + 1], dp[n])

# for num in dp:
#     print(num, end=" ")

print(dp[n + 1])
