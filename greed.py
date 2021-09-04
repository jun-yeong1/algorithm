n, k = map(int, input().split())  ## 백준 11047
coins = []
count = 0
for i in range(n):
    coins.append(int(input()))
coins.reverse()
for coin in coins:
    count += k // int(coin)
    k %= int(coin)
print(count)
##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