from collections import deque

t = int(input())

for _ in range(t):
    a, b = map(int, input().split())
    q = deque()
    visited = [False] * (10000 + 4)
    visited[a] = True
    q.append([0, a, ""])

    while q:
        cnt, num, s = q.popleft()

        if num == b:
            print(s)
            break

        # D
        new_num = (num * 2) % 10000
        if not visited[new_num]:
            q.append([cnt + 1, new_num, s + "D"])
            visited[new_num] = True

        # S
        new_num = num - 1
        if new_num < 0:
            new_num = 9999
        if not visited[new_num]:
            q.append([cnt + 1, new_num, s + "S"])
            visited[new_num] = True

        # L
        first = num // 1000
        second = num % 1000
        new_num = second * 10 + first
        if not visited[new_num]:
            q.append([cnt + 1, new_num, s + "L"])
            visited[new_num] = True

        # R
        first = num % 10
        second = num // 10
        new_num = first * 1000 + second
        if not visited[new_num]:
            q.append([cnt + 1, new_num, s + "R"])
            visited[new_num] = True
