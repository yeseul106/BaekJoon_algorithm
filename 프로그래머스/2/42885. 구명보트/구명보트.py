def solution(people, limit):
    answer = 0
    people = sorted(people)
    lo, hi = 0, len(people) - 1
    while lo <= hi:
        if people[lo] + people[hi] <= limit:
            lo += 1
            hi -= 1
        else:
            hi -= 1
        answer += 1
    return answer