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
const int MAX_X = 1000000;
int N;
int scores[100005], x[100005];
int x_to_idx[1000005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;
	memset(x_to_idx, -1, sizeof(x_to_idx));

	for (int i = 0; i < N; i++) {
		cin >> x[i];
		x_to_idx[x[i]] = i;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 2 * x[i]; j <= MAX_X; j += x[i]) {
			if (x_to_idx[j] != -1) {
				scores[i]++;
				scores[x_to_idx[j]]--;
			}
		}
	}

	for (int i = 0; i < N; i++)
		cout << scores[i] << ' ';
}