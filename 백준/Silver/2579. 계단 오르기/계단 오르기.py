def pb(b):
    for v in b:
        print(v)
    print()

n = int(input())
scores = [0] * 304
dp = [[0] * 3 for _ in range(304)]
for i in range(n):
    scores[i] = (int(input()))

dp[0][1] = scores[0]
dp[1][1] = scores[1]
dp[1][2] = scores[0] + scores[1]

for i in range(2, n):
    dp[i][1] = max(dp[i - 2][1] + scores[i], dp[i - 2][2] + scores[i])
    dp[i][2] = dp[i - 1][1] + scores[i]

print(max(dp[n - 1][1], dp[n - 1][2]))