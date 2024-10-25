fee_list = list(map(int, input().split()))
parking_info = [list(map(int, input().split())) for _ in range(3)]

start_time_sort = sorted(parking_info, key=lambda x: x[0])
end_time_sort = sorted(parking_info, key=lambda x: x[1], reverse=True)

start_time, end_time = start_time_sort[0][0], end_time_sort[0][1]
ret = 0
for time in range(start_time + 1, end_time + 1):
    car_cnt = 0
    for info in parking_info:
        if info[0] < time <= info[1]:
            car_cnt += 1
    ret += car_cnt * fee_list[car_cnt - 1]
print(ret)