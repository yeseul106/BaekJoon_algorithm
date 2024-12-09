num = [-1, 1]
ret = 0

def check(result, numbers, target):
    sum = 0
    # print(result)
    for idx in range(len(result)):
        sum += numbers[idx] * num[result[idx]]
    if sum == target:
        return True
    return False

def backtracking(result, numbers, target, depth, end):
    global ret
    if depth == end:
        if(check(result, numbers, target)):
            ret += 1
        return
    for i in range(2):
        result.append(i)
        backtracking(result, numbers, target, depth + 1, end)
        result.pop()

def solution(numbers, target):
    backtracking([], numbers, target, 0, len(numbers))
    return ret