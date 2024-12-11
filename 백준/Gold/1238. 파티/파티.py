import heapq

n, m, x = map(int, input().split())
graph = [[] for _ in range(n + 1)]
dist_arr = []

for _ in range(m):
    a, b, w = map(int, input().split())
    graph[a].append((b, w))

# 각 노드에서 다른 모든 노드로의 최단 경로 계산
for i in range(1, n + 1):
    dist = [int(1e9)] * (n + 1)
    dist[i] = 0
    q = []
    heapq.heappush(q, [0, i])

    while q:
        now_dist, now_node = heapq.heappop(q)

        if now_dist > dist[now_node]:
            continue

        for next_node, weight in graph[now_node]:
            distance = now_dist + weight

            # 더 짧으면 갱신
            if distance < dist[next_node]:
                dist[next_node] = distance
                heapq.heappush(q, [distance, next_node])

    dist_arr.append(dist)

ret = 0
for i in range(n):
    path = dist_arr[i][x] + dist_arr[x - 1][i + 1]
    ret = max(ret, path)

print(ret)
