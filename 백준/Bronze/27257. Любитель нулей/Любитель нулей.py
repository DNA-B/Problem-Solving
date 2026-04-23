n = input()
for i in range(len(n)-1,-1,-1):
    if n[i] != '0':
        print(n[:i].count('0'))
        break