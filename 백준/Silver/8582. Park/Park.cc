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
int w[1000005], west_max[1000005], east_max[1000005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> w[i];

	int cur_west_mx = 0;
	for (int i = 0; i < N; i++) {
		if (w[i] > cur_west_mx)
			cur_west_mx = w[i];
		west_max[i] = cur_west_mx;
	}

	int cur_east_mx = 0;
	for (int i = N - 1; i >= 0; i--) {
		if (w[i] > cur_east_mx)
			cur_east_mx = w[i];
		east_max[i] = cur_east_mx;
	}

	for (int i = 0; i < N; i++)
		cout << west_max[i] << " " << east_max[i] << "\n";
}