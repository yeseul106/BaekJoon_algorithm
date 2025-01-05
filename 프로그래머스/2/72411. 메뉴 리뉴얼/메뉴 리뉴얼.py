from itertools import combinations
from collections import defaultdict

def solution(orders, course):
    answer = []
    order_dict = defaultdict(int)
    
    for order in orders:
        order = sorted(list(order))
        for course_num in course:
            for com_list in combinations(order, course_num):
                order_dict[com_list] += 1
    
    for course_num in course:
        max_ret = [0, []]
        for combi in order_dict:
            if len(combi) == course_num and order_dict[combi] >= 2:
                if max_ret[0] < order_dict[combi]:
                    max_ret[0] = order_dict[combi]
                    max_ret[1] = [combi]
                elif max_ret[0] == order_dict[combi]:
                    max_ret[1].append(combi)
        for ret in max_ret[1]:
            ret = "".join(ret)
            answer.append(ret)
        
    answer = sorted(answer)

    return answer