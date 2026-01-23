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
int A[4005], B[4005], C[4005], D[4005];
vector<int> AB_sum, CD_sum;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i] >> B[i] >> C[i] >> D[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			AB_sum.push_back(A[i] + B[j]);
			CD_sum.push_back(C[i] + D[j]);
		}
	}

	sort(CD_sum.begin(), CD_sum.end());

	ll res = 0;
	for (int x : AB_sum) {
		auto range = equal_range(CD_sum.begin(), CD_sum.end(), -x);
		res += distance(range.X, range.Y);
	}

	cout << res;
}