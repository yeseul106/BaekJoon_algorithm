def solution(queue1, queue2):
    answer = 0  # 횟수는 0부터 시작
    queue1_sum = sum(queue1)
    queue2_sum = sum(queue2)

    # 전체 합이 홀수라면 절반으로 나눌 수 없으므로 -1 반환
    if (queue1_sum + queue2_sum) % 2 != 0:
        return -1

    total_sum = queue1_sum + queue2_sum
    half = total_sum // 2

    queue = queue1 + queue2  # 두 큐를 이어붙임
    queue1_point, queue2_point = 0, len(queue1)

    while queue1_point < queue2_point and queue2_point < len(queue):
        # 목표 합을 달성한 경우
        if queue1_sum == half:
            return answer

        # 현재 합이 목표보다 큰 경우 -> queue1의 왼쪽 값을 제거
        if queue1_sum > half:
            queue1_sum -= queue[queue1_point]
            queue1_point += 1
        # 현재 합이 목표보다 작은 경우 -> queue2의 값을 queue1으로 이동
        else:
            queue1_sum += queue[queue2_point]
            queue2_point += 1

        answer += 1

    # 목표를 달성하지 못한 경우 -1 반환
    return -1
