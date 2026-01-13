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
ll costs[300005], mem[5]; // { i번째 인덱스에서 U,D,S,P,C를 만들 수 있는 최소 비용 }
string S;
unordered_map<char, int> UOSPC = { { 'U', 0 }, { 'O', 1 }, { 'S', 2 }, { 'P', 3 }, { 'C', 4 } };
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> costs[i];

	fill(mem, mem + 5, LL_INF);

	for (int i = 0; i < N; i++) {
		int idx = UOSPC[S[i]];
		if (idx == 0)
			mem[idx] = min(mem[idx], costs[i]);
		else if (idx != 0 && idx > 0)
			mem[idx] = min(mem[idx], mem[idx - 1] + costs[i]);
	}

	cout << (mem[UOSPC['C']] == LL_INF ? -1 : mem[UOSPC['C']]);
}