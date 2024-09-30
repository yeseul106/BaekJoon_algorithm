# number를 n진수로 변환하는 코드
def convert(number, n):
    if number == 0:
        return '0'
    NUMBERS = "0123456789ABCDEF"
    res = ""
    while number > 0 :
        number , mod = divmod(number, n)
        res += NUMBERS[mod]
    return res[::-1] # 문자열 뒤집기

def solution(n, t, m, p):
    arr = ''
    answer = ''
    
    # n진법으로 바꾸면서 미리 배열을 구해놓는데, 그 길이가 t*m 보다 클 때까지만 구해놓기
    num = 0;
    while len(arr) <= (t*m):
        arr += convert(num, n)
        num += 1

    cnt = 0
    idx = p-1
    
    for i in range(t):
        answer += arr[idx] 
        idx += m
    
    return answer