from collections import deque

def solution(name):
    non_a = []
    turn_up_down, turn_right_left = 0, int(1e9)
    size = len(name)
    
    for idx, ch in enumerate(name):
        if ch == 'A':
            continue
        turn_up_down += min(ord(ch) - ord('A'), 26 - (ord(ch) - ord('A')))
        non_a.append(idx)
    
    
    
    q = deque()
    q.append([0, [0], 0])
    
    while q:

        idx, path, cnt = q.popleft()
        
        # print(path)
        
        clear_num = len(non_a)
        for pos in non_a:
            if pos in path:
                clear_num -= 1
        
        if clear_num == 0:
            turn_right_left = min(turn_right_left, cnt)
            break
        else:
            left_idx = (idx + 1) % size
            right_idx = (idx + size - 1) % size
            
            left_path = path + [left_idx]
            q.append([left_idx, left_path, cnt + 1])
                
            right_path = path + [right_idx]
            q.append([right_idx, right_path , cnt + 1])
    
    return turn_right_left + turn_up_down