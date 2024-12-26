from collections import defaultdict

def solution(want, number, discount):
    answer = 0
    buy_list = defaultdict(int)
    get_list= defaultdict(int)
    clear_list = defaultdict(bool)
    
    for idx, item in enumerate(want):
        buy_list[item] = number[idx]
        get_list[item] = 0
        clear_list[item] = False
    
    lo, hi = 0, 0
    get_size = 0
    clear_size = 0
    
    while lo <= hi and hi < len(discount):
        if get_size < 10:
            if discount[hi] in buy_list:
                get_list[discount[hi]] += 1
                if get_list[discount[hi]] >= buy_list[discount[hi]] and not clear_list[discount[hi]]:
                    clear_size += 1
                    clear_list[discount[hi]] = True
            get_size += 1
            hi += 1
        if get_size == 10:
            if clear_size == len(want):
                answer += 1
            if discount[lo] in buy_list:
                get_list[discount[lo]] -= 1
                if get_list[discount[lo]] < buy_list[discount[lo]] and clear_list[discount[lo]]:
                    clear_size -= 1
                    clear_list[discount[lo]] = False
            lo += 1
            get_size -= 1

    return answer