def solution(today, terms, privacies):
    answer = []
    today = list(map(int, today.split('.')))
    term_info = dict()
    
    for term in terms:
        type, month = term.split()
        term_info[type] = month
    
    for idx, privacy in enumerate(privacies):
        flag = False
        day, type = privacy.split()
        day_list = list(map(int, day.split('.')))
        
        last_year = day_list[0] + (day_list[1] + int(term_info[type])) // 12
        last_month = (day_list[1] + int(term_info[type])) % 12
        if last_month == 0:
            last_month = 12
            last_year -= 1
        last_day = day_list[2] - 1
        if last_day == 0:
            last_month -= 1
            if last_month == 0:
                last_year -= 1
                last_month = 12
            last_day = 28
        
        # print(last_year, last_month, last_day)
        
        if last_year < today[0]:
            flag = True
        elif last_year == today[0]:
            if last_month < today[1]:
                flag = True
            elif last_month == today[1]:
                if last_day < today[2]:
                    flag = True
        if flag:
            answer.append(idx + 1)
    
    return answer