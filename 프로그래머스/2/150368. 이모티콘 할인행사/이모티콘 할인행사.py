from itertools import product

sale_percent = [10, 20, 30, 40]

def solution(users, emoticons):
    answer = [0, 0]
    size = len(emoticons)
    
    # 이모티콘 할인할 수 있는 비율 : 10%, 20%, 30%, 40%
    # 중복 순열로 각 이모티콘마다 할인하는 비율을 먼저 픽스
    for idxs in product(range(4), repeat=size):
        plus_subscribe_cnt = 0
        sold_price= 0
        
        for user in users:
            total_money = 0
            
            for emoticon_idx in range(size):
                if sale_percent[idxs[emoticon_idx]] >= user[0]:
                    total_money += (emoticons[emoticon_idx] * (100 - sale_percent[idxs[emoticon_idx]]) * 0.01)
        
            if total_money >= user[1]:
                plus_subscribe_cnt += 1
                total_money = 0
            
            sold_price += total_money
        
        if answer[0] < plus_subscribe_cnt:
            answer = [plus_subscribe_cnt, sold_price]
        elif answer[0] == plus_subscribe_cnt:
            if answer[1] < sold_price:
                answer = [plus_subscribe_cnt, sold_price]
    
    # print(answer)
    return answer