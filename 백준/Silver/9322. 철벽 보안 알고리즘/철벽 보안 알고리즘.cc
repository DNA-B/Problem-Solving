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
int T;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		string s;
		unordered_map<int, string> oneIdx;
		unordered_map<string, int> twoIdx;
		for (int i = 0; i < N; i++) {
			cin >> s;
			oneIdx[i] = s;
		}

		for (int i = 0; i < N; i++) {
			cin >> s;
			twoIdx[s] = i;
		}

		string arr[1005];
		for (int i = 0; i < N; i++)
			cin >> arr[i];

		for (int i = 0; i < N; i++) {
			string one = oneIdx[i];
			int two = twoIdx[one];
			cout << arr[two] << ' ';
		}

		cout << '\n';
	}
}