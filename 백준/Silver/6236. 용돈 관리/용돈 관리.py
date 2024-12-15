n, m = map(int, input().split())
arr = []
for _ in range(n):
    arr.append(int(input()))

left, right = max(arr), max(arr) * n
ret = int(1e9)

while left <= right:
    mid = (left + right) // 2

    # print("mid : ", mid)

    # mid 값으로 m번 안에 매일 매일 돈을 다 쓸 수 있을까 ?
    cnt = 1
    money = mid
    for i in range(n):
        # print("money : ", money, "arr[i] : ", arr[i])
        if money >= arr[i]:
            money -= arr[i]
        else:
            cnt += 1
            money = mid
            money -= arr[i]

    # print("cnt", cnt)
    if cnt > m:
        left = mid + 1
    else:
        ret = min(ret, mid)
        right = mid - 1
    # print("==============")

print(ret)