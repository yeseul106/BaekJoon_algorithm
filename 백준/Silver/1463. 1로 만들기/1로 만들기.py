n = int(input())
dp = [int(1e9)] * (n + 1)
dp[0] = 0
dp[1] = 0

for i in range(1, n + 1):
    if i + 1 <= n:
        dp[i + 1] = min(dp[i + 1], dp[i] + 1)
    if i * 2 <= n:
        dp[i * 2] = min(dp[i * 2], dp[i] + 1)
    if i * 3 <= n:
        dp[i * 3] = min(dp[i * 3], dp[i] + 1)

print(dp[n])
