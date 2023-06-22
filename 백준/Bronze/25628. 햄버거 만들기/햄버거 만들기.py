def make_hamburger(A, B):
    return min(A // 2, B)

if __name__ == "__main__":
    A, B = map(int, input().split())
    print(make_hamburger(A=A, B=B))