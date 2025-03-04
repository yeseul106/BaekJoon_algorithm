def pb(b):
    for v in b:
        print(v)
    print()

def solution(triangle):
    answer = 0
    max_h = len(triangle)
    max_r = len(triangle[max_h-1])
    dp = [[0] * max_r for _ in range(max_h)]
    
    dp[0][0] = triangle[0][0]
    
    for h in range(len(triangle)):
        for r in range(len(triangle[h])):
            if 0 <= h-1 < max_h:
                if 0 <= r-1:
                    dp[h][r] = max(dp[h-1][r-1], dp[h-1][r]) + triangle[h][r]
                else:
                    dp[h][r] = dp[h-1][r] + triangle[h][r]
        
    return max(dp[h])