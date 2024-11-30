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
int T, N;
int arr[10005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> T;

	while (T--) {
		int mx = -1;

		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> arr[i];

		sort(arr, arr + N); // [2, 4, 5, 7, 9]

		for (int i = 2; i < N; i++) // {2, 5, 9} , {4, 7}로 나누는 것이 최소 간격
			mx = max(mx, arr[i] - arr[i - 2]);
		mx = max(mx, arr[1] - arr[0]); // {2, 5, 9, 7, 4}일 때, {2, 4} 고려

		cout << mx << "\n";
	}
}