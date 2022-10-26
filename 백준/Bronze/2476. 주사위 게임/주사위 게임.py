rep = int(input())

prize = []

for i in range(rep):
    a, b, c = map(int, input().split())

    if (a == b and b == c):
        prize.append(10000 + (a * 1000))
    elif (a != b and b != c and c != a):
        prize.append(max(a, b, c)*100)
    else:
        if (a == b and b != c):
            prize.append(1000+(a*100))
        elif (a == c and c != b):
            prize.append(1000+(a*100))
        elif (b == c and c != a):
            prize.append(1000+(b*100))


print(max(prize))
