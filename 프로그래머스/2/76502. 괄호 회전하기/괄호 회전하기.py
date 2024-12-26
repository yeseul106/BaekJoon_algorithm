def solution(s):
    answer = 0
    for i in range(len(s)):
        idx = i
        stack = []
        flag = True
        for _ in range(len(s)):
            ch = s[idx % len(s)]
            if ch in ['[', '{', '('] :
                stack.append(ch)
            else:
                if len(stack) > 0:
                    before_ch = stack.pop()
                    if ch == ']' and before_ch != '[':
                        flag = False
                        break
                    if ch == '}' and before_ch != '{':
                        flag = False
                        break
                    if ch == ')' and before_ch != '(':
                        flag = False
                        break
                # 닫는 괄호가 있는데 여는 괄호 없으니까
                else:
                    flag = False
                    break
            idx += 1
        if len(stack) == 0 and flag:
            answer += 1
    return answer