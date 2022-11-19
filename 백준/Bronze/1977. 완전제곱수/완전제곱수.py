m = int(input())
n = int(input())

sum = 0
min_n = 0

for i in range(1, 101):
    if (i * i) >= m and (i * i) <= n:
        sum += i * i
        if min_n == 0:
            min_n = i * i


if min_n == 0:
    print(-1)
else:
    print(sum)
    print(min_n)
