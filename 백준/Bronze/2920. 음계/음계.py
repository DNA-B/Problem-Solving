lst = list(map(int, input().split()))

if (sorted(lst) == lst):
    print('ascending')
elif (sorted(lst, reverse=True) == lst):
    print('descending')
else:
    print('mixed')