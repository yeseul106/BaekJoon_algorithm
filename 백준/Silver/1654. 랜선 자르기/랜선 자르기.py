K, N = map(int, input().split())
arr = []
for _ in range(K):
    arr.append(int(input()))
# print(arr)

left = 1
right = max(arr)
ret = 0

while left <= right:
    mid = (left + right) // 2
    total = 0
    for lan in arr:
        total += (lan // mid)
    if total >= N:
        left = mid + 1
        ret = max(ret, mid)
    else:
        right = mid - 1

print(ret)