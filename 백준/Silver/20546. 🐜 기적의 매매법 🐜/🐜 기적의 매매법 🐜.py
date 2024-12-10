money = int(input())
arr = list(map(int, input().split()))

# 준현이 계산
# 준현이는 주식을 살 수 있다면 무조건 최대한 많이 산다. 준현이는 욕심쟁이이기 때문에, 주식을 살 수 있다면 가능한 만큼 즉시 매수한다
# 준현이는 한 번 산 주식은 절대 팔지 않는다.
joon_cnt = 0
joon_money = money

# 성민이 계산
# 모든 거래는 전량 매수와 전량 매도로 이루어진다. 현재 가지고 있는 현금이 100원이고 주가가 11원이라면 99원어치의 주식을 매수하는 것이다. 단, 현금이 100원 있고 주가가 101원이라면 주식을 살 수 없다. 성민이는 빚을 내서 주식을 하지는 않는다.
# 3일 연속 가격이 전일 대비 상승하는 주식은 다음날 무조건 가격이 하락한다고 가정한다. 따라서 현재 소유한 주식의 가격이 3일째 상승한다면, 전량 매도한다. 전일과 오늘의 주가가 동일하다면 가격이 상승한 것이 아니다.
# 3일 연속 가격이 전일 대비 하락하는 주식은 다음날 무조건 가격이 상승한다고 가정한다. 따라서 이러한 경향이 나타나면 즉시 주식을 전량 매수한다. 전일과 오늘의 주가가 동일하다면 가격이 하락한 것이 아니다.
sung_money = money
sung_cnt = 0
before_money = 0

up_cnt = 0
down_cnt = 0

for price in arr:
    joon_buy_cnt = joon_money // price
    joon_money -= (joon_buy_cnt * price)
    joon_cnt += joon_buy_cnt

    # 전날 대비 상승
    if before_money < price:
        up_cnt += 1
        down_cnt = 0
    elif before_money > price:
        down_cnt += 1
        up_cnt = 0
    else:
        up_cnt = 0
        down_cnt = 0

    if up_cnt >= 3:
        if sung_cnt > 0:
            # 전량 매도 -> 다 팔기
            sung_money += (price * sung_cnt)
            sung_cnt = 0

    if down_cnt >= 3:
            # 전량 매수 -> 다 사기
            sung_buy_cnt = (sung_money // price)
            sung_cnt += sung_buy_cnt
            sung_money -= (sung_buy_cnt * price)

    before_money = price

joon_result = (joon_money + arr[len(arr) -1] * joon_cnt)
sung_result = (sung_money + arr[len(arr) -1] * sung_cnt)

if joon_result > sung_result:
    print("BNP")
elif joon_result < sung_result:
    print("TIMING")
else:
    print("SAMESAME")