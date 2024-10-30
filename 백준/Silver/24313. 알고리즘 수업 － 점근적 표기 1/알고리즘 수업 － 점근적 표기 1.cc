#include <cstdio>

int main() {
	int a1, a0, c, n;
	
	scanf("%d %d %d %d", &a1, &a0, &c, &n);
	
	if ((a1 * n + a0 <= c*n) && a1 <= c) {
		printf("1");
	} else {
		printf("0");
	}
}