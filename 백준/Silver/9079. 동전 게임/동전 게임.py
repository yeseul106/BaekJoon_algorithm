from collections import deque

def pb(b):
    for v in b:
        print(v)
    print()

toggle_arr = [
    "111000000",
    "000111000",
    "000000111",
    "100100100",
    "010010010",
    "001001001",
    "100010001",
    "001010100"
]

t = int(input())

for _ in range(t):
    board = [list(input().split()) for _ in range(3)]
    visited = [False] * (int("111111111", 2) + 1)

    # 비트 마스킹 사용하기 위해서 맵 변환 -> H : 0, T : 1 바꾸고 str으로 이어붙이기
    flat_str = ""
    for i in range(3):
        for j in range(3):
            if board[i][j] == 'H':
                flat_str += "0"
            elif board[i][j] == 'T':
                flat_str += "1"
    # print(flat)
    # flat = int(flat_str, 2)

    q = deque()
    is_complete = False
    q.append([flat_str, 0])
    visited[int(flat_str, 2)] = True

    while q:
        s, cnt = q.popleft()

        # print(int(s, 2))

        if int(s, 2) == 0 or int(s, 2) == 511:
            print(cnt)
            is_complete = True
            break

        for i in range(8):
            result = int(s, 2) ^ int(toggle_arr[i], 2)
            binary_result = bin(result)[2:].zfill(len(s))

            if not visited[result]:
                q.append([binary_result, cnt + 1])
                visited[result] = True

    if not is_complete:
        print("-1")