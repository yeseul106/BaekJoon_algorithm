from collections import defaultdict
from itertools import combinations

def lower_bound(lo, hi, target, arr):
    while lo <= hi:
        mid = (lo + hi) // 2
        if arr[mid] < target:
            lo = mid + 1
        else:
            hi = mid - 1
    return lo

def solution(info, query):
    answer = []
    dict = defaultdict(list)
        
    for i in info:
        tmp_list = i.split(" ")
        score = int(tmp_list.pop())

        for i in range(5):
            case = list(combinations([0,1,2,3], i))
            for c in case:
                tmp = tmp_list.copy()
                for idx in c:
                    tmp[idx] = "-"
                key = ''.join(tmp)
                dict[key].append(score) 
                
    for value in dict.values():
        value.sort()

    for q in query:
        query_list = q.split(" and ")
        tmp = query_list.pop().split(" ")
        query_list.append(tmp[0])
        
        target = int(tmp[1])
        
        query_str = ''.join(query_list)
        find_list = dict[query_str]
        size = len(find_list) 
        
        if size == 1:
            if find_list[0] >= target:
                answer.append(1)
            else:
                answer.append(0)
        else:
            find_idx = lower_bound(0, size - 1, target, find_list)
            answer.append(size - find_idx)
        
    return answer