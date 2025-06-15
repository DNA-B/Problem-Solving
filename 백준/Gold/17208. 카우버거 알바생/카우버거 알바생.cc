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
int N, M, K;
int mem[305][305];
vector<pair<int, int>> v;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M >> K;

	for (int x, y, i = 0; i < N; i++) {
		cin >> x >> y;
		v.push_back({ x, y });
	}

	for (int i = 0; i < N; i++) {
		auto [burger, fries] = v[i];
        
		for (int j = M; j >= burger; j--) {
			for (int k = K; k >= fries; k--) {
				mem[j][k] = max(mem[j][k], mem[j - burger][k - fries] + 1);
            }
		}
	}

	cout << mem[M][K];
}