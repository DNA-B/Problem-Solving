#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

/******** MACRO ********/
#define BOUND 2001
#define MAX 1'000'000'001
#define MOD 10000
#define ll long long
#define X first
#define Y second
/***********************/

using namespace std;

/****** VARIABLEs ******/
int n, m, a, b;
int union_find;
vector<int> p(1000001, -1);
/***********************/

int uf_find(int x) {
	if (p[x] < 0)
		return x;

	return p[x] = uf_find(p[x]);
}

void uf_union(int a, int b) {
	a = uf_find(a);
	b = uf_find(b);

	if (a == b) // 부모 같음
		return;

	if (p[a] == p[b]) // 둘의 rank가 같다면 둘 중 하나의 rank - 1
		p[a]--;

	if (p[a] < p[b]) // rank가 더 작은 쪽이 큰 쪽에 합쳐진다.
		p[b] = a;
	else
		p[a] = b;
}

void findParent(int a, int b) {
	a = uf_find(a);
	b = uf_find(b);

	if (a == b)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	// freopen("input.txt", "r", stdin);

	cin >> n >> m;

	while (m--) {
		cin >> union_find >> a >> b;

		if (union_find == 0)
			uf_union(a, b);
		else
			findParent(a, b);
	}

	return 0;
}