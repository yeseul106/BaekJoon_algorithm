def solution(msg):
    answer = []
    
    ALPHA = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    dic = {}
    dic = {chr(i + 64) : i for i in range(1, 27)}
    
    w = c = 0
    while True:
        c += 1
        
        #끝까지 왔으면
        if c == len(msg):
            answer.append(dic[msg[w:c]])
            break
        
        while msg[w:c+1] not in dic:
            dic[msg[w:c+1]] = len(dic) + 1
            answer.append(dic[msg[w:c]])
            w = c
            
    return answer