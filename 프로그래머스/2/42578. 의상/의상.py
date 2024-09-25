def solution(clothes):
    closet = {} 
    answer = 1
    
    for name, kind in clothes:
        if kind in closet.keys():
            closet[kind] += [name]
        else:
            closet[kind] = [name]
            
    for key, value in closet.items():
        answer *= (len(value)+1)
    
    return answer-1