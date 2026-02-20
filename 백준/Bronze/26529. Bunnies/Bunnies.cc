#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

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
int mem[50];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	mem[0] = 1, mem[1] = 1;
	for (int i = 2; i <= 45; i++)
		mem[i] = mem[i - 1] + mem[i - 2];

	cin >> N;

	int x;
	while (N--) {
		cin >> x;
		cout << mem[x] << '\n';
	}
}