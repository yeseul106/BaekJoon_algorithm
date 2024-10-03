from collections import defaultdict

def solution(record):
    answer = []
    new_arr = []
    nickname_dict = defaultdict(str)
    flag_dict = defaultdict(bool)
    
    # 배열로 바꾸기
    for s in record:
        str_list = s.split(" ")
        new_arr.append(str_list)

    # change 찾아서 배열 다시 바꾸기
    for i in range(len(new_arr)):
        type = new_arr[i][0]
        
        if type == "Leave":
            flag_dict[new_arr[i][1]] = True
        
        if type == "Change":
            nickname_dict[new_arr[i][1]] = new_arr[i][2]
        
        if type == "Enter":
            if flag_dict[new_arr[i][1]]:
                nickname_dict[new_arr[i][1]] = new_arr[i][2] 
                del flag_dict[new_arr[i][1]]
            nickname_dict[new_arr[i][1]] = new_arr[i][2]
    
    # 출력
    for arr in new_arr:
        type = arr[0]
        if type == "Enter":
            answer.append(str(nickname_dict[arr[1]] + "님이 들어왔습니다."))
        if type == "Leave" :
            answer.append(str(nickname_dict[arr[1]] + "님이 나갔습니다."))
        
    return answer