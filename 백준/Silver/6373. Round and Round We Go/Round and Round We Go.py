import sys

def check(a, b):
    t = a

    for _ in range(len(a)):
        if t == b: 
            return 1
        
        t = t[1:] + t[0]
    return 0

while True:
    try:
        s = sys.stdin.readline().rstrip()
        n, flag = int(s), 1

        for i in range(1, len(s) + 1):
            t = str(n * i).zfill(len(s))

            if len(t) > len(s) or not check(s, t): 
                flag = 0

        print(f'{s} is {"" if flag else "not "}cyclic')
    except:
        break