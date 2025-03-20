def check(mid, stones, k):
    cnt = 0
    for stone in stones:
        if stone - (mid - 1) <= 0:
            cnt += 1
            if cnt >= k:
                return False
        else:
            cnt = 0
    return True

def solution(stones, k):
    lo, hi = 1, max(stones)
    answer = 0
    
    while lo <= hi:
        mid = (lo + hi) // 2
        if check(mid, stones, k):
            answer = mid
            lo = mid + 1
        else:
            hi = mid - 1

    return answer