from itertools import combinations

def solution(n, q, ans):
    answer = 0
    for arr in combinations(range(1, n + 1), 5):
        arr_corret_cnt = 0
        for idx, query in enumerate(q):
            correct_cnt = 0
            for num in arr:
                for query_num in query:
                    if num == query_num:
                        correct_cnt += 1
            if correct_cnt == ans[idx]:
                arr_corret_cnt += 1
        if arr_corret_cnt == len(ans):
            answer += 1
    
    return answer