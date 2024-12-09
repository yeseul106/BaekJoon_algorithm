n = int(input())
arr = list(map(int, input().split()))

arr = sorted(arr)
ret = 0

def search(num, num1_idx, idx):
    left, right = 0, n - 1

    while left <= right:
        mid = (left + right) // 2

        if arr[mid] == num and mid != num1_idx and mid != idx:
            return mid
        elif arr[mid] < num:
            left = mid + 1
        else:
            right = mid - 1

    return -1

for idx in range(0, n):
    number = arr[idx]
    for num1_idx in range(0, n):
        if num1_idx == idx:
            continue
        num1 = arr[num1_idx]
        num2 = number - num1

        num2_idx = search(num2, num1_idx, idx)

        if num2_idx != -1 and num2_idx != idx and num2_idx != num1_idx:
            # print(idx, num1_idx, num2_idx)
            ret += 1
            break

print(ret)