n = int(input())
arr = list(map(int, input().split()))

stack = []
answer = [-1] * n

for i in range(n):
    if len(stack) == 0:
        stack.append([arr[i], i])
    else:
        # print("stack : ", stack)
        # print(arr[i])
        while True:
            if len(stack) == 0 or stack[len(stack) - 1][0] >= arr[i] :
                stack.append([arr[i], i])
                break
            else:
                num, idx = stack.pop()
                answer[idx] = arr[i]

for num in answer:
    print(num, end=" ")
