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
int D, P, mx = -1;
int mem[100005];
vector<pair<int, int>>pipes;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> D >> P;

	for (int l, c, i = 0; i < P; i++) {
		cin >> l >> c;
		pipes.push_back({ l, c });
	}

	mem[0] = INT_MAX;
	for (int i = 0; i < P; i++) {
		auto [l, c] = pipes[i];
		for (int j = D; j >= l; j--)
			mem[j] = max(mem[j], min(mem[j - l], c));
	}

	cout << mem[D];
}