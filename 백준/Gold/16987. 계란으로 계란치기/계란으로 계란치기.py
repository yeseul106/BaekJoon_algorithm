import copy

def backtracking(puzzle, n, start, cnt):
    global ret
    # 오른쪽으로 가면서 계란을 들어보기
    if start < n and puzzle[start][0] <= 0:
        while start + 1 < n:
            start += 1
            if start < n and puzzle[start][0] > 0:
                break

    if start == n or puzzle[start][0] <= 0:
        ret = max(ret, cnt)
        return

    for i in range(n):
        if i == start:
            continue
        # 손에 들고 있는 계란으로 깨지지 않은 다른 계란 중에서 하나를 친다.
        if puzzle[i][0] > 0:
            puzzle[i][0] -= puzzle[start][1]
            puzzle[start][0] -= puzzle[i][1]
            next = start + 1

            cnt = 0
            for j in range(n):
                if puzzle[j][0] <= 0:
                    cnt += 1

            backtracking(puzzle, n, next, cnt)
            puzzle[start][0] += puzzle[i][1]
            puzzle[i][0] += puzzle[start][1]

    ret = max(ret, cnt)

n = int(input())
puzzle = []
visited = [False] * n
ret = 0

for _ in range(n):
    power, weight = map(int, input().split())
    puzzle.append([power, weight])

puzzle_copy = copy.deepcopy(puzzle)
backtracking(puzzle_copy, n, 0, 0)

print(ret)
