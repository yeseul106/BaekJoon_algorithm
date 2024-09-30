def convert(number, n):
    if number == 0:
        return '0'
    NUMBERS = "0123456789"
    res = ''
    while number > 0:
        number, mod = divmod(number, n)
        res += NUMBERS[mod]
    return res[::-1]

def isPrime(n):
    n = int(n)

    if n <= 1:
        return False
    for i in range(2, int(n**(1/2))+1): # 절반까지만 보면 됨
        if n % i == 0:
            return False
    return True

def solution(n, k):
    answer = 0
    change_num = convert(n, k)
    
    num_list = change_num.split("0")
    
    for num in num_list:
        if num == '':
            continue
        if (isPrime(num)):
            print(num)
            answer += 1
    
    return answer