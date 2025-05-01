#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

//========= MACRO =========//
#define PI 3.1415926535897932
#define INF 0x3f3f3f3f
#define LL_INF 1e18
#define ll long long
#define X first
#define Y second
//=========================//

//======= VARIABLEs =======//
int N;
set<int> s;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 1; i <= N; i++)
		s.insert(i);

	auto st = s.begin();
	auto en = --s.end();
	cout << *st << " " << *en;

	while (st != en) {
		if (next(st) == en) break;
		else st++;
		if (st == prev(en)) break;
		else en--;
		cout << " " << *st << " " << *en;
	}

	if (s.size() & 1)
		cout << " " << *st;
}