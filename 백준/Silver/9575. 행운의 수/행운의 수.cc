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
		int N, M, K;
		int A[55], B[55], C[55];
		set<int> lucky_nums;

		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> A[i];

		cin >> M;
		for (int i = 0; i < M; i++)
			cin >> B[i];

		cin >> K;
		for (int i = 0; i < K; i++)
			cin >> C[i];

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				for (int k = 0; k < K; k++) {
					int x = A[i] + B[j] + C[k];
					string tmp = to_string(x);
					bool flag = true;

					for (char ch : tmp) {
						if (ch != '5' && ch != '8') {
							flag = false;
							break;
						}
					}

					if (flag)
						lucky_nums.insert(x);
				}
			}
		}

		cout << lucky_nums.size() << "\n";
	}
}