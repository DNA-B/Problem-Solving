import sys

x, y = sys.stdin.readline().rstrip().split()
print(bin(int(x,2) + int(y,2))[2:]) # 0bXXXXX에서 0b 제외하고 출력
