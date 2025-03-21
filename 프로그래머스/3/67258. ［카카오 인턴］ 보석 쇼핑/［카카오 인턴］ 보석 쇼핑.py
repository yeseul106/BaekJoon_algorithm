from collections import defaultdict

def solution(gems):
    
    if len(gems) == 1:
        return 1
    
    gems_size = len(gems)
    answer = [1, gems_size]
    
    lo, hi = 0, 0
    key = set(gems)
    dict = defaultdict(int)
    dict[gems[lo]] += 1
    key_num = 1
    
    if key_num == len(key):
        answer = [lo + 1, hi + 1]
    
    while lo <= hi and hi <= gems_size - 1:
        # print("before dict : ", dict)
        if key_num == len(key):
            if hi - lo < answer[1] - answer[0]:
                answer = [lo + 1, hi + 1]
            dict[gems[lo]] -= 1
            if dict[gems[lo]] == 0:
                key_num -= 1
            lo += 1
        else:
            hi += 1
            if hi >= gems_size:
                break
            dict[gems[hi]] += 1
            if dict[gems[hi]] == 1:
                key_num += 1
            
        # print("lo, hi : ", lo, hi)
        # print("after dict : ", dict)
        # print("===============")
    
    return answer