from collections import deque
from mailcap import subst

N, M = map(int, input().split())
edges = [[] for _ in range(N + 1)] # 보통 노드의 수는 1부터 시작하니까 헷갈리지 않기 위해서
indegree = [0] * (N + 1)
visited = [0] * (N + 1)
q = deque()

# 선수 과목 정보 입력 받기
for _ in range(M):
    a, b = map(int, input().split())
    edges[a].append(b)
    indegree[b] += 1

# 선수 과목이 없는 과목부터 큐에 넣기
for i in range(1, N + 1):
    if indegree[i] == 0:
        q.append(i)
        visited[i] = 1

while q:
    subject = q.popleft()

    for v in edges[subject]:
        indegree[v] -= 1
        if indegree[v] == 0:
            q.append(v)
            visited[v] = visited[subject] + 1

for i in range(1, N + 1):
    print(visited[i], end=" ")
