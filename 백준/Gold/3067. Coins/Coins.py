t = int(input())
for _ in range(t):
    n = int(input())
    coin_arr = list(map(int, input().split()))
    money = int(input())
    dp = [0] * (money + 1)

    dp[0] = 1

    for coin in coin_arr:
        for i in range(coin, money + 1):
            dp[i] += dp[i - coin]

    print(dp[money])
