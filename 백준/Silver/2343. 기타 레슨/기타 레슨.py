n, m = map(int, input().split())
media_len_arr = list(map(int, input().split()))

left, right = 1, sum(media_len_arr)
ret = int(1e9)

while left <= right:
    mid = (left + right) // 2

    # m개의 mid(블루레이의 길이) 길이를 가진 블루레이로 영상을 차례로 담을 수 있는가 ?
    # mid를 넘지 않을 동안 계속 더해보기
    need_num = 0
    total = 0
    can_record = True

    for idx in range(n):
        if media_len_arr[idx] > mid:
            can_record = False
            break
        if total + media_len_arr[idx] > mid:
            need_num += 1
            total = 0
        total += media_len_arr[idx]

    if total <= mid:
        need_num += 1

    if need_num > m:
        can_record = False

    if can_record:
        right = mid - 1
        ret = min(ret, mid)
    else:
        left = mid + 1

print(ret)
