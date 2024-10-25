word = input()
alpha_num = [0] * 26

for ch in word:
    alpha_num[ord(ch) - ord('a')] += 1

for alpha in alpha_num:
    print(alpha, end=' ')
