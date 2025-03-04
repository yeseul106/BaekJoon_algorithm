from itertools import combinations_with_replacement

def solution(n, info):
    answer = []
    case_arr = []
    
    # n개의 화살이 들어갈 점수의 index를 중복해서 뽑는다고 생각
    for idxs in combinations_with_replacement(range(11), n):
        case = [0] * 11
        for idx in idxs:
            case[idx] += 1
        case_arr.append(case)
    
    for case in case_arr:
        apeach_score, lion_score = 0, 0
        for i in range(11):
            if info[i] == 0 and case[i] == 0:
                continue
            if info[i] >= case[i]:
                apeach_score += 10 - i
            else:
                lion_score += 10 - i
                
        if apeach_score < lion_score:
            answer.append([lion_score - apeach_score, case])
    
    answer = sorted(answer, key = lambda x: -x[0])
    
    if len(answer) == 0:
        return [-1]
    
    if len(answer) == 1:
        return answer[0][1]

    max_diff = answer[0][0]
    tmp_arr = []
    
    for diff, arr in answer:
        if diff < max_diff:
            break
        tmp_arr.append(arr[::-1])
    
    tmp_arr = sorted(tmp_arr)
    
    return tmp_arr.pop()[::-1]