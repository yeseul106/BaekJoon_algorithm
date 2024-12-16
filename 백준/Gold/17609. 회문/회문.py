t = int(input())

for _ in range(t):
    s = input()

    lo, hi = 0, len(s) - 1
    change_cnt = 0
    result = 0
    change_info = []

    while lo <= hi:
        # print(lo, hi)
        # print(s[lo], s[hi])
        if s[lo] == s[hi]:
                lo += 1
                hi -= 1
        else:
            if change_cnt == 0 and s[lo + 1] == s[hi]:
                change_cnt += 1
                change_info = [lo, hi, 'L']
                lo += 1
            elif change_cnt == 0 and s[lo] == s[hi - 1]:
                change_cnt += 1
                change_info = [lo, hi, 'H']
                hi -= 1
            elif change_cnt == 1:
                if change_info[2] == 'L':
                    lo = change_info[0]
                    hi = change_info[1] - 1
                else:
                    lo = change_info[0] + 1
                    hi = change_info[1]
                change_cnt += 1
            else:
                result = 2
                break
        # print()


    if result != 2:
        if change_cnt == 0:
            result = 0
        else:
            result = 1

    print(result)