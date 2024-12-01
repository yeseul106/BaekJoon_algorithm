N, M = map(int, input().split())
trees = list(map(int, input().split()))

left = 0
right = max(trees)
ret = 0

while left <= right:
    mid = (left + right) // 2
    # print("left mid right ", left, mid, right)
    # 구할 수 있는 나무 총 길이 구하기
    total_get_tree = 0
    for tree in trees:
        if tree > mid:
            total_get_tree += tree - mid
    if total_get_tree >= M:
        left = mid + 1
        ret = max(ret, mid)
    else:
        right = mid - 1
print(ret)