a = int(input())
array = list(map(int, input().split()))
min = array[0]
max = array[0]

for i in range(1,a):
    if min>array[i]:
        min = array[i]
    if max<array[i]:
        max = array[i]

print(min,end=" ")
print(max)