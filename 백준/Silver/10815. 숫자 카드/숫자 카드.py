N = int(input())
cards = list(map(int, input().split()))
M = int(input())
inputs = list(map(int, input().split()))

cards = sorted(cards)
# print(cards)

for num in inputs:
    left, right = 0, N -1
    check = False
    while left <= right:
        mid = (left + right) // 2
        if cards[mid] == num:
            check = True
            break
        elif cards[mid] < num:
            left = mid + 1
        else:
            right = mid - 1
    if check:
        print("1", end=" ")
    else:
        print("0", end=" ")