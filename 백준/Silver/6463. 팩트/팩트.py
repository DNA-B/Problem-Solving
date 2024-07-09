import sys
input = sys.stdin.readline

while True:
    try:
        N = input().rstrip()
        fact = 1
        
        for i in range(1, int(N) + 1):
          fact *= i

        fact = str(fact)
        fact = fact[::-1]

        for ch in fact:
            if ch != '0':
                for _ in range(5 - len(N)):
                    print(' ', end='')
                print(f'{N} -> {ch}')
                break
    except:
        break