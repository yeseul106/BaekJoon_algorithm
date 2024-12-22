from collections import defaultdict

def solution(k, tangerine):
    answer = 0
    total = 0
    info = defaultdict(int)
    
    for item in tangerine:
        info[item] += 1
    
    for tuple in info.items():
        total += tuple[1]
    
    # 제일 개수가 적은 숫자부터 없애면서 k 맞추기
    sort_items = sorted(info.items(), key = lambda x: x[1])
    
    answer = len(sort_items)
    
    for temp in sort_items:
        if total <= k:
            break
        answer -= 1
        total -= temp[1]
    
    if total < k:
        answer += 1
        
    return answer