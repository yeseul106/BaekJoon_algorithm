from collections import defaultdict
import math

def calc_fee(fees, time):
    # 기본 요금이 나오는 경우
    if time <= fees[0]:
        return fees[1]
    return fees[1] + math.ceil((time - fees[0]) / fees[2]) * fees[3]

def calc_time(time1, time2):
    time1_list = time1.split(":")
    time2_list = time2.split(":")
    
    hour_diff = int(time2_list[0]) - int(time1_list[0])
    min_diff = int(time2_list[1]) - int(time1_list[1])
    
    return hour_diff*60 + min_diff
    
    
def solution(fees, records):
    answers = defaultdict(int) # key : 자동차 번호, value : 주차 금액
    record_info = []
    
    # 정보 배열 만들기    
    for record in records:
        list = record.split(" ")
        record_info.append(list)
    
    idx = 0
    for record in record_info:
        time = 0
        flag = False
        fee = 0
        # IN 이면
        if record[2] == "IN":
            # 리스트에 OUT 있는지 확인
            for i in range(idx + 1, len(record_info)):
                num = record_info[i][1]
                type = record_info[i][2]
                if num == record[1] and type == "OUT":
                    ## 주차한 시간 구하기
                    time = calc_time(record[0], record_info[i][0])
                    flag = True
                    break
            if not flag:
                time = calc_time(record[0], "23:59")
        answers[record[1]] += time
        idx += 1
    
    # TODO : key 값을 기준으로 정렬해서 뿌리기
    answers = sorted(answers.items())
    new_answer = []
    
    for item in answers:
        new_answer.append(calc_fee(fees, item[1]))
        
    return new_answer