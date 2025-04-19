import heapq
from collections import deque

n = int(input())
class_info = []

classroom = []
for _ in range(n):
    class_num, class_start, class_end = map(int, input().split())
    tmp = [class_start, class_end, class_num]
    class_info.append(tmp)

class_info.sort(key=lambda x: (x[0], x[1]))
class_info = deque(class_info)

max_classroom_num = 1 

for _ in range(n):
    c_start, c_end, c_num = class_info.popleft()

    if len(classroom) == 0:
        heapq.heappush(classroom, [c_end, c_end - c_start, max_classroom_num])
    else:
        classroom_info = heapq.heappop(classroom)
        
        if classroom_info[0] <= c_start:
            heapq.heappush(classroom, [c_end, classroom_info[1]])
        else:
            heapq.heappush(classroom, classroom_info)
            max_classroom_num += 1
            heapq.heappush(classroom, [c_end, max_classroom_num])

print(max_classroom_num)
