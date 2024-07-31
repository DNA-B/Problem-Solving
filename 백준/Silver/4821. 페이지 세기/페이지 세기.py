import sys

input = sys.stdin.readline

while True:
    N = int(input().rstrip())
    cnt = [0] * 1001

    if N == 0:
        break

    docs = input().rstrip().split(',')
    lst = [list(map(int, doc.split('-'))) for doc in docs]
    
    for page in lst:
        if len(page) == 1 and page[0] <= N:
            cnt[page[0]] = 1;
        elif len(page) == 2 and page[0]:
            for idx in range(page[0], page[1] + 1):
                if idx <= N:
                    cnt[idx] = 1;
    
    print(cnt.count(1))