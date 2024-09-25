def solution(arr1, arr2):
    answer = []
    for i in range(len(arr1)):
        new_row = [] 
        for j in range(len(arr2[0])):
            sum_value = 0
            for k in range(len(arr1[0])): 
                sum_value += arr1[i][k] * arr2[k][j]
            new_row.append(sum_value)
        answer.append(new_row)
    
    return answer