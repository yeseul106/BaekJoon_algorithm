import math

idx = 0;

def make_list(str):
    global idx
    idx = 0
    str_list = []
    
    while idx < len(str) -1:
        new_str = str[idx:idx+2].lower()
        if new_str.isalpha():
            str_list.append(new_str)
        idx += 1
    return str_list


def solution(str1, str2):
    # 두 글자씩 자르기
    str1_list = make_list(str1)
    str2_list = make_list(str2)
    
    intersection_num = 0

    for s1 in str1_list:
        if s1 in str2_list:
            intersection_num += 1
            str2_list.remove(s1)
            
    union_num = len(str1_list) + len(str2_list)
    
    if union_num == 0:
        return 65536
    else:
        return math.floor((intersection_num / union_num) * 65536)