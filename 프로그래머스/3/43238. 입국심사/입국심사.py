def solution(n, times):
    left = 1
    right = int(1e9) * int(1e9)
    answer = right
    
    while left <= right:
        mid = (left + right) // 2
        
        # mid 시간 안에 모든 사람 입국 심사 가능?
        total = 0
        for time in times:
            total += (mid // time)
        
        if total >= n:
            answer = min(answer, mid)
            right = mid - 1
        else:
            left = mid + 1
    
    return answer