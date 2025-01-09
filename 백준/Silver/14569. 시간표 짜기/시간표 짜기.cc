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
int N, M, k, p;
int stu[10005][55], res[1005];
vector<int> v[1005];
//=========================//


int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> k;
		while (k--) {
			int t;
			cin >> t;
			v[i].push_back(t);
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> p;
		for (int q, j = 0; j < p; j++) {
			cin >> q;
			stu[i][q] = 1;
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			bool flag = true;
			for (int l = 0; l < v[j].size(); l++) {
				if (!stu[i][v[j][l]]) {
					flag = false;
					break;
				}
			}

			if (flag)
				res[i]++;
		}
	}

	for (int i = 0; i < M; i++)
		cout << res[i] << '\n';
}