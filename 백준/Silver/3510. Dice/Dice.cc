#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
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
int N, total = 0;
double E = 0.0;
pair<int, int> arr[1005];
vector<int> nums[1005];
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int x, i = 0; i < N; i++) {
		cin >> x;
		arr[i] = { x, i };
		total += x;
	}

	sort(arr, arr + N);

	for (int i = 0; i < N; i++) {
		auto [x, idx] = arr[i];
		for (int j = 0; j < x; j++) {
			nums[idx].push_back(total);
			E += (total--) / (double)x;
		}
	}

	cout << fixed << setprecision(5) << E << '\n';

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < nums[i].size(); j++)
			cout << nums[i][j] << ' ';
		cout << '\n';
	}
}