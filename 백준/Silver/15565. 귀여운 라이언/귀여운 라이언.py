n, k = map(int, input().split())
arr = list(input().split())

lo, hi = 0, 0
cnt = 0
ret = int(1e9)

while lo <= hi:
    # print("lo : ", lo, "hi: ", hi, "cnt : ", cnt)

    if cnt >= k:
        ret = min(ret, hi - lo)
        # print("ret : ", ret)
        if arr[lo] == '1':
            cnt -= 1
        lo += 1
    else:
        if hi >= n:
            break
        if arr[hi] == '1':
            cnt += 1
        hi += 1

if ret == int(1e9):
    print(-1)
else:
    print(ret)

