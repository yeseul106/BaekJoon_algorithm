def check(tmp):
    num1 = int(tmp/100)
    num2 = int((tmp%100)/10)
    num3 = tmp%10
    if (num1-num2) == (num2-num3):
        return True
    else:
        return False

a = int(input())
count=0

for i in range(1,a+1):
    if i<100:
        count+=1
    else:
        if check(i):
            count+=1

print(count)
