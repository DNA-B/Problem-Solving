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
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	int x;
	vector<vector<string>> v(N);
	for (int i = 0; i < N; i++) {
		cin >> x;

		string menu;
		while (x--) {
			cin >> menu;
			v[i].push_back(menu);
		}
	}

	cout << v[0].size() << '\n';
	for (string menu : v[0])
		cout << menu << '\n';
}