from collections import deque

# inTime(member[0], member[1], bus_hour, bus_minute)
def in_time(target_hour, target_minute, bus_hour, bus_minute):
    if target_hour < bus_hour:
        return True
    elif target_hour == bus_hour:
        if target_minute <= bus_minute:
            return True
    return False

# answer_format(last_member[0], last_member[1])
def answer_format(hour, minute):
    return str(hour).zfill(2) + ":" + str(minute).zfill(2)

def solution(n, t, m, timetable):
    answer = ''
    members = []
    
    for time in timetable:
        tmp = list(map(int, time.split(":")))
        members.append(tmp)
        
    members.sort(key = lambda x: (x[0], x[1]))
    members = deque(members)
    
    bus_hour = 9
    bus_minute = 0
    
    # n회 번 t분 마다 셔틀이 옴
    # 맨 마지막 회차의 사람이 다 탔으면 한명 쫒아내고
    # 다 안탔으면 그 버스 시간에 내가 도착하면 됨
    
    for turn_idx in range(n):
        up_people = []
        list_member = list(members)
        
        for member in list_member:
            if in_time(member[0], member[1], bus_hour, bus_minute) and len(up_people) < m:
                up_people.append(member)
                members.popleft()
                
        if turn_idx == n - 1:
            if len(up_people) == m:
                last_member_hour, last_member_minute = up_people.pop()
                last_member_minute -= 1
                if last_member_minute < 0:
                    last_member_hour -= 1
                    last_member_minute = 59
                answer = answer_format(last_member_hour, last_member_minute)
            else:
                answer = answer_format(bus_hour, bus_minute)
        
        bus_minute += t
        if bus_minute >= 60:
            bus_hour += 1
            bus_minute -= 60
            
    return answer