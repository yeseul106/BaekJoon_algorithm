from collections import deque

heights = []

for i in range(9):
    heights.append(int(input()))

seven_height = deque()
result = []

def backtracking(start, depth):
    if depth == 7:
        # 7명의 배열 만들어짐 -> 합이 100인지 확인
        total = sum(seven_height)
        if total == 100:
            sort_list = sorted(seven_height)
            result.append(sort_list)
            return

    for i in range(start + 1, 9):
        seven_height.append(heights[i])
        backtracking(i, depth + 1)
        seven_height.pop()

backtracking(-1, 0)

for one in result[0]:
    print(one)