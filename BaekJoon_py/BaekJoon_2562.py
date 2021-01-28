array = []
index=-1
max=-1

for i in range(0,9):
    tmp=int(input())
    array.append(tmp)
    if max < array[i]:
        max = array[i]
        index = i

print(max)
print(index+1)

