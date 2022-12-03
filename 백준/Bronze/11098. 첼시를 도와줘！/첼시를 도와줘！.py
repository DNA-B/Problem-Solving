n = int(input())

for i in range(n):
    rep = int(input())
    dic = {}

    for j in range(rep):
        c, name = input().split()
        dic[int(c)] = name
    res = sorted(dic, reverse=True)
    print(dic[res[0]])
