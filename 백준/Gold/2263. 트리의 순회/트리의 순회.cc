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
int in[100005], post[100005], idx[100005];
//=========================//

void solve(int in_st, int in_en, int post_st, int post_en) {
	if (in_st > in_en || post_st > post_en)
		return;

	int root_idx = idx[post[post_en]]; // inorder에서 루트의 위치를 파악
	// inorder [ROOT -> L -> R]
	cout << in[root_idx] << ' '; // ROOT
	solve(in_st, root_idx - 1, post_st, post_st - in_st + root_idx - 1); // L
	solve(root_idx + 1, in_en, post_en - in_en + root_idx, post_en - 1); // R
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> in[i];
		idx[in[i]] = i;
	}

	for (int i = 0; i < N; i++)
		cin >> post[i];

	solve(0, N - 1, 0, N - 1);
	return 0;
}