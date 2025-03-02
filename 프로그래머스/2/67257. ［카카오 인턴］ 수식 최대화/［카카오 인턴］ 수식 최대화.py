from collections import deque
from collections import defaultdict
import copy

ret = 0
op = ["+", "-", "*"]
op_stack = deque()

def change_expression(expression_list):
    global op_stack
    for i in range(len(expression_list)):
        ch = expression_list[i]
        if ch == '+' or ch == '-' or ch == '*':
            expression_list[i] = '.'
            op_stack.append(ch)
    return ''.join(expression_list)

def calc(op_list, num_stack, op_stack):
    while len(op_list) > 0:
        result = deque()
        op = op_list.popleft()
        
        while len(num_stack) > 1 and len(op_stack) > 0:
            num1 = int(num_stack.popleft())
            num2 = int(num_stack.popleft())
            now_op = op_stack.popleft()
            
            if now_op == op:
                tmp = 0
                if op == '*':
                    tmp = num1 * num2
                elif op == '-':
                    tmp = num1 - num2
                else:
                    tmp = num1 + num2
                if len(num_stack) != 0:
                    num_stack.appendleft(tmp)
                else:
                    result.append(tmp)
            else:
                op_stack.append(now_op)
                result.append(num1)
                num_stack.appendleft(num2)
            
        if len(num_stack) == 1:
            result.append(num_stack.pop())
        num_stack = result

    return abs(sum(result))
    
def backtracking(visited, arr, expression, stack):
    global ret
    if len(arr) == 3:
        op_list = deque()
        copy_num_stack = copy.deepcopy(stack)
        copy_op_stack = copy.deepcopy(op_stack)
        for o in arr:
            op_list.append(op[o-1])
        ret = max(ret, calc(op_list, copy_num_stack, copy_op_stack))
        return
    for i in range(1, 4):
        if not visited[i]:
            visited[i] = True
            arr.append(i)
            backtracking(visited, arr, expression, stack)
            arr.pop()
            visited[i] = False

def solution(expression):
    visited = [False] * 4
    arr = []
    expression_list = list(expression)
    expression = change_expression(expression_list)
    stack = expression.split(".")
    stack = deque(stack)
    backtracking(visited, arr, expression, stack)
    return ret