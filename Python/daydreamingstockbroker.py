money = 100
N = int(input())
prev_price = int(input())

for i in range(N-1):
    price = int(input())

    if price > prev_price:
        bought = min(int(money/prev_price), 100000)
        money += bought * (price - prev_price)

    prev_price = price


print(money)




