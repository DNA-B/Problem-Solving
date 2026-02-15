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
int N, K;
int arr[5005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> K;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N, greater<int>());

	int tmp = 0;
	for (int i = 0; i < K; i++)
		tmp += arr[i];

	int minus = K * (K - 1) / 2;
	cout << tmp - minus << "\n";
}