import sys
import math

cnt = int(sys.stdin.readline().rstrip())
inputList = list(map(int, sys.stdin.readline().rstrip().split(' ')))

for i in inputList:
    if i == 1:
        cnt -= 1;
        continue;
        
    for j in range(2, int(math.sqrt(i))+1):
        if i % j == 0:
            cnt -= 1
            break

print(cnt)