def A_B(A, B):
    return (A+B) * (A-B)
  
  
A, B = map(int, input().split())
print(A_B(A, B))
