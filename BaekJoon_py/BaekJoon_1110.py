n = input()  #string 타입
num = int(n)  #int 타입

if num>=0 and num<=9:
    n="0"+n
origin = n
#print(n)
news = ""
count =0

while origin!=news:
    if count>0:
        n=news
        num = int(news)
    if num>=0 and num<=9:
        sum = 0 + num
    else:
        sum= int(n[0]) + int(n[1])

    if sum>=0 and sum<=9:
        sums = "0"+str(sum)
        #print(sums)
    else:
        sums = str(sum)
    news= n[1]+sums[1]
    #print("새로운 수",news)
    count+=1

print(count)

