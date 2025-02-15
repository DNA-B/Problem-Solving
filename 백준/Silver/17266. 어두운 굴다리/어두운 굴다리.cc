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
int N, M;
int arr[100005];
vector<int> itv;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M;

	for (int x, i = 0; i < M; i++)
		cin >> arr[i];

	itv.push_back(arr[0]);
    itv.push_back(N - arr[M - 1]);
    
	for (int i = 1; i < M; i++) {
		int tmp = ceil((arr[i] - arr[i - 1]) / 2.0);
		itv.push_back(tmp);
	}

	sort(itv.begin(), itv.end(), greater<>());
	cout << itv[0];
}