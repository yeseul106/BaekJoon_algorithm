from collections import deque

N, M = map(int, input().split())
indegree = [0] * (N + 1)
edges = [[] for _ in range(N + 1)]
q = deque()

for _ in range(M):
    a, b = map(int, input().split())
    indegree[b] += 1
    edges[a].append(b)

for i in range(1, N + 1):
    if indegree[i] == 0:
        q.append(i)

while q:
    x = q.popleft()
    print(x, end=" ")

    for y in edges[x]:
        indegree[y] -= 1
        if indegree[y] == 0:
            q.append(y)
