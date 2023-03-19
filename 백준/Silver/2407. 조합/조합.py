import math

n, m = map(int, input().split())

num = math.factorial(n)
deno = (math.factorial(n - m)) * (math.factorial(m))

print(num // deno)