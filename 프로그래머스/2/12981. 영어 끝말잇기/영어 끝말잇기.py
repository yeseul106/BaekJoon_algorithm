def solution(n, words):
    answer = [0, 0]
    afterWords = []
    beforeWord = ""
    
    for idx, word in enumerate(words):
        if idx != 0:
            if beforeWord[-1] != word[0] or word in afterWords:
                answer[0] = idx % n + 1
                answer[1] = idx // n + 1
                break
        afterWords.append(word)
        beforeWord = word

    return answer