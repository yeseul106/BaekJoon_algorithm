def solution(files):
    answer = []
    ret = []
    
    for idx, file in enumerate(files):
        head, number = '', ''
        head_end = False
        number_end = False
        for ch in file:
            if ch.isdigit() and not number_end:
                head_end = True
                number += ch
            else:
                if not head_end:
                    head += ch.lower()
                else:
                    number_end = True
        answer.append([head, int(number), idx, file])
    
    answer = sorted(answer, key = lambda x: (x[0], x[1], x[2]))
    
    for file in answer:
        ret.append(file[3])
        
    return ret