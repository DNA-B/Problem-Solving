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
int N, M, S;
int chkForm[2005];
vector<int> pending[4005];
set<int> res;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> M >> S;

	int i, t;
	int moneyCnt = 0;
	while (M--) {
		cin >> i >> t;

		if (t == 0) { // i번 회원이 폼 제출
			chkForm[i] = 1;
			moneyCnt++;
			for (int member : pending[moneyCnt]) {
				if (!chkForm[member])
					res.insert(member);
			}
		}
		else if (t == 1) { // i번 회원이 돈 납부
			pending[moneyCnt + S].push_back(i);
		}
	}

	if (res.empty()) {
		cout << -1;
		exit(0);
	}

	for (int member : res)
		cout << member << '\n';
}