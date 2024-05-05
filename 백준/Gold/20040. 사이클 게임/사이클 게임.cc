#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 500'000
#define MAX 1'000'000'001
#define MOD 10000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int N, M;
vector<int> p(BOUND, -1);
/***********************/

int uf_find(int x) {
	if (p[x] < 0)
		return x;

	return p[x] = uf_find(p[x]);
}

bool uf_union(int a, int b) {
	a = uf_find(a);
	b = uf_find(b);

	if (a == b) // 예제 2) 3의 부모가 0인 상태에서	0이 3과 이어지려고하면 사이클 발생
		return false;

	if (p[a] == p[b]) // 둘의 rank가 같다면 둘 중 하나의 rank - 1
		p[a]--;

	if (p[a] < p[b]) // rank가 더 작은 쪽이 큰 쪽에 합쳐진다.
		p[b] = a;
	else
		p[a] = b;

	return true;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;

	for (int a, b, i = 1; i <= M; i++) {
		cin >> a >> b;

		if (!uf_union(a, b)) {
			cout << i;
			exit(0);
		}
	}

	cout << 0; // 사이클 X

	return 0;
}