import sys

st = []
n = int(sys.stdin.readline())

for _ in range(n):
    order = sys.stdin.readline().split()

    if order[0] == '1':
        st.append(int(order[1]))
    elif order[0] == '2':
        if len(st) != 0:
            print(st[len(st)-1])
            st.pop()
        else:
            print(-1)
    elif order[0] == '3':
        print(len(st))
    elif order[0] == '4':
        if len(st) == 0:
            print(1)
        else:
            print(0)
    elif order[0] == '5':
        if len(st) != 0:
            print(st[len(st)-1])
        else:
            print(-1)
