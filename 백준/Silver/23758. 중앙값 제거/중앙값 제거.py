import heapq
import math

n = int(input())
arr = list(map(int, input().split()))
ret = 0
q = []

arr = sorted(arr)

# 규칙 -> arr의 절반 앞부분이 계속 돌음
idx = ((n + 1) // 2) - 1
while idx >= 0:
    heapq.heappush(q, -arr[idx])
    idx -= 1

while q:
    num = heapq.heappop(q) * -1
    ret += int(math.log2(num))

print(ret + 1)

