answer = -1
visited = [False] * 9

def check(result, k, dungeons):
    cnt = 0
    for idx in result:
        if dungeons[idx][0] <= k:
            k -= dungeons[idx][1]
            cnt += 1
    return cnt

def backtracking(result, k, dungeons, depth):
    global answer
    
    if depth == len(dungeons):
        answer = max(answer, check(result, k, dungeons))
        return
    
    for i in range(len(dungeons)):
        if not visited[i]:
            visited[i] = True
            result.append(i)
            backtracking(result, k, dungeons, depth + 1)
            visited[i] = False
            result.pop()

def solution(k, dungeons):
    backtracking([], k, dungeons, 0);
    return answer