#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
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
pair<int, int> arr[1500100];
int mem[1500100];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i].X >> arr[i].Y;

	for (int i = 0; i < N; i++) {
		auto [day, price] = arr[i];
		mem[i + day] = max(mem[i + day], mem[i] + price);
		mem[i + 1] = max(mem[i + 1], mem[i]);
	}

	cout << mem[N];
}