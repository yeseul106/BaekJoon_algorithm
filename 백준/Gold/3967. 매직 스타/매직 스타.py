def pb(b):
    for v in b:
        print(v)
    print()

board = [list(input()) for _ in range(5)]
alpha = [(0 + i) for i in range(13)]
pick_alpha = [False] * 13
visited = [False] * 13
have_to_pick_num = 0
result_bool = False
new_board = [['.'] * 9 for _ in range(5)]

index_board =[[(0 + i, 4 - i) for i in range(4)],
              [(1, 1 + 2 * i) for i in range(4)],
              [(3, 1 + 2 * i) for i in range(4)],
              [(1 + i, 1 + i) for i in range(4)],
              [(4 - i, 4 + i) for i in range(4)],
              [(0 + i, 4 + i) for i in range(4)]]

for i in range(5):
    for j in range(9):
        if board[i][j] == 'x':
            have_to_pick_num += 1
        elif board[i][j] != '.':
            pick_alpha[ord(board[i][j]) - ord('A') + 1] = True


def make_board(result):
    global new_board
    idx = 0
    for i in range(5):
        for j in range(9):
            if board[i][j] == 'x':
                new_board[i][j] = chr(result[idx] + ord('A') - 1)
                idx += 1
            elif board[i][j] != '.':
                new_board[i][j] = board[i][j]
    return new_board

def check(new_board):
    for arr in index_board:
        sum = 0
        for pos in arr:
            sum += ord(new_board[pos[0]][pos[1]]) - ord('A') + 1
        if sum != 26:
            return False
    return True

def backtracking(result, depth):
    global result_bool
    if result_bool:
        return
    if depth == have_to_pick_num:
        # print(result)
        new_board = make_board(result)
        if check(new_board):
            # pb(new_board)
            result_bool = True
        return
    for i in range(1, 13):
        if not pick_alpha[i] and not visited[i]:
            result.append(i)
            visited[i] = True
            backtracking(result, depth + 1)
            result.pop()
            visited[i] = False

backtracking([], 0)

for i in range(5):
    ret = ''
    for j in range(9):
        ret += new_board[i][j]
    print(ret)
