#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

long long mem[51][51][51];

long long w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;
	
	if (mem[a][b][c] != 0)
		return mem[a][b][c];

	if (a > 20 || b > 20 || c > 20) {
		mem[a][b][c] = w(20, 20, 20);
		return mem[a][b][c];
	}

	if (a < b && b < c) {
		mem[a][b][c] =  w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
		return mem[a][b][c];
	}

	mem[a][b][c] =  w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
	return mem[a][b][c];
}

int main() {
	int a, b, c;

	while (1) {
		scanf("%d %d %d", &a, &b, &c);

		if (a == -1 && b == -1 && c == -1)
			return 0;
		else
			printf("w(%d, %d, %d) = %lld\n", a, b, c, w(a, b, c));
	}
	
	return 0;
}