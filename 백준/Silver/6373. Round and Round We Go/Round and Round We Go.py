import sys

def check(n, tmp):
    t = tmp

    for _ in range(len(n)):
        if t == n: 
            return True 
        t = t[1:] + t[0]
    return False

def solve():
    N = sys.stdin.readline().rstrip()
    s = int(N)
    flag = 1

    for i in range(1, len(N) + 1):
        tmp = str(s * i).zfill(len(N))
        
        if not check(N, tmp):
            flag = 0;
            break;
    
    print(f'{N} is {"" if flag else "not "}cyclic')

while True:
    try: 
        solve()
    except:
        break