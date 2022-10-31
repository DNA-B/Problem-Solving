s = int(input())
n = 1
cnt = 1
while n * ((n + 1) / 2) <= s :
    n += 1
    cnt += 1
print(cnt - 1)