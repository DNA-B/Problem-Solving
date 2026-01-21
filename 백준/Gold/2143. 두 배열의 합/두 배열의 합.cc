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
int N, M;
ll T;
ll A[1005], B[1005];
vector<ll> vA, vB;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> B[i];

	for (int i = 0; i < N; i++) {
		ll sum = 0;
		for (int j = i; j < N; j++) {
			sum += A[j];
			vA.push_back(sum);
		}
	}

	for (int i = 0; i < M; i++) {
		ll sum = 0;
		for (int j = i; j < M; j++) {
			sum += B[j];
			vB.push_back(sum);
		}
	}

	sort(vA.begin(), vA.end());
	sort(vB.begin(), vB.end());

	ll res = 0;
	for (ll sum : vA)
		res += upper_bound(vB.begin(), vB.end(), T - sum) - lower_bound(vB.begin(), vB.end(), T - sum);

	cout << res;
}