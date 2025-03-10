t = int(input())  # 테스트 케이스 수

for _ in range(t):
    n = int(input())  # 동전 종류의 개수
    coins = list(map(int, input().split()))  # 동전 금액들
    target = int(input())  # 만들어야 할 금액
    
    # dp[i] = i원을 만드는 방법의 수
    dp = [0] * (target + 1)
    dp[0] = 1  # 0원을 만드는 방법은 1가지 (아무 동전도 사용하지 않음)
    
    # 각 동전에 대해
    for coin in coins:
        # coin원부터 target원까지
        for i in range(coin, target + 1):
            # i-coin원을 만드는 방법의 수에 현재 동전을 추가하는 경우의 수를 더함
            dp[i] += dp[i - coin]
    
    print(dp[target])  # 결과 출력