n, m = map(int, input().split())
arr = list(map(int, input().split())) + [0] * 4
ret = 0

lo, hi = 0, 1
sum = arr[0] + arr[hi]

while lo <= hi and hi < n:
    if sum > m:
        if lo == hi:
            hi += 1
            sum += arr[hi]
        sum -= arr[lo]
        lo += 1
    else: 
        ret = max(ret, sum)
        hi += 1
        sum += arr[hi]

print(ret)