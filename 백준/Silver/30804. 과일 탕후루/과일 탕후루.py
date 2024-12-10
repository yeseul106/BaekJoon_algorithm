n = int(input())
pick = [0] * 10
arr = list(map(int, input().split()))

if n == 1:
    print("1")
else:
    ret, fruit_cnt = 0, 0
    lo, hi = 0, 1
    pick[arr[lo]] += 1
    pick[arr[hi]] += 1

    for i in range(1, 10):
        if pick[i] > 0:
            fruit_cnt += 1

    while lo <= hi and hi < n:
        # 꽃혀 있는 과일 종류 몇 개인지 구하기
        # print(lo, hi)
        # print(pick)
        if fruit_cnt <= 2:
            ret = max(ret, hi - lo + 1)
            hi += 1
            if hi < n:
                if pick[arr[hi]] == 0:
                    fruit_cnt += 1
                pick[arr[hi]] += 1
        else:
            pick[arr[lo]] -= 1
            if pick[arr[lo]] <= 0:
                fruit_cnt -= 1
            lo += 1
    print(ret)
