import heapq
from collections import deque

def solution(priorities, location):
    pq = []
    q = deque()
    result = [0] * len(priorities)
    
    for idx, priority in enumerate(priorities):
        heapq.heappush(pq, [-priority, idx])
        q.append([idx, priority])
    
    num = 1
    
    while q:
        idx, priority = q.popleft()
        h_p, h_i = heapq.heappop(pq)
        
        if priority < -h_p:
            q.append([idx, priority])
            heapq.heappush(pq, [h_p, h_i])
        else:
            result[idx] = num
            num += 1
                
    return result[location]