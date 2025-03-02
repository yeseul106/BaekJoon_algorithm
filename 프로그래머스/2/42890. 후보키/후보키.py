from itertools import combinations
from collections import defaultdict

def solution(relation):
    answer = 0
    combi = []
    size = len(relation[0])
    dict = defaultdict(int)
    
    for i in range(size):
        combi = combi + list(combinations(range(size), i))
    
    for case in combi:
        if len(case) == 0:
            continue
        s_case = ''
        for idx in case:
            s_case += str(idx)
        
        tmp_set = set()
        for row in relation:
            s = ''
            for idx in case:
                s += row[idx]
            tmp_set.add(s)

        if len(tmp_set) == len(relation):
            flag = True
            for key in dict.keys():
                contain_num = 0
                print("key : ", key)
                print("s_case : ", s_case)
                for ch in s_case:
                    if ch in key:
                        contain_num += 1
                print("contain_num : ", contain_num)
                if contain_num == len(key):
                    flag = False
            print("=======")
            if flag:
                answer += 1
                dict[s_case] = 1
    if answer == 0:
        answer = 1
    return answer