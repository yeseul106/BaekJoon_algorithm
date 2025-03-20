from itertools import combinations

answer = [0, -1]
n,m = map(int, input().split())
info = []

for _ in range(n):
    info.append(list(input().split()))

for i in range(n + 1):
    for arr in combinations(range(n), i):
        possible = [False] * m
        possible_music_cnt = 0
        for idx in arr:
            for j in range(m):
                if info[idx][1][j] == 'Y':
                    possible[j] = True

        for j in range(m):
            if possible[j]:
                possible_music_cnt += 1

        if answer[0] < possible_music_cnt:
            answer = [possible_music_cnt, i]
        elif answer[0] != 0 and answer[0] == possible_music_cnt:
            if answer[1] == -1:
                answer = [possible_music_cnt, i]
            else:
                answer = [possible_music_cnt, min(answer[1], i)]

print(answer[1])

