a,b=map(int,input().split())  #map => mapping / split으로 공백문자 구분
if a>b:
    print(">")
elif a==b:
    print("==")
else:
    print("<")
