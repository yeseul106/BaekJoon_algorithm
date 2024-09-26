from collections import deque

def solution(cacheSize, cities):
    answer = 0
    
    q = deque()
    
    if cacheSize == 0:
        answer = 5 * len(cities)
        return answer
    
    for city in cities:
        city = city.lower()
        # 먼저 캐시에서 찾기
        if city in q:
            answer += 1
            q.remove(city)
            q.append(city)
        else:
            answer += 5
            
            # 캐시 크기가 넘지 않으면 추가
            if len(q) < cacheSize or len(q) == 0:
                q.append(city)
            else:
                q.popleft()
                q.append(city)
    
    return answer