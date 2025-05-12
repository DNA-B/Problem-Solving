#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
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
int T, M;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> T;

	while (T--) {
		vector<int> medians; // 중앙값 저장
		priority_queue<int> mxh; // 최대 힙 (하위 절반)
		priority_queue<int, vector<int>, greater<int>> mnh; // 최소 힙 (상위 절반)

		cin >> M;

		for (int x, i = 1; i <= M; i++) {
			cin >> x;

			// 첫 번째 숫자는 최대 힙에
			if (mxh.empty()) {
				mxh.push(x);
				medians.push_back(mxh.top());
				continue;
			}

			if (x < mxh.top())
				mxh.push(x);
			else
				mnh.push(x);

			if (mxh.size() > mnh.size() + 1) {
				mnh.push(mxh.top());
				mxh.pop();
			}
			else if (mnh.size() > mxh.size()) {
				mxh.push(mnh.top());
				mnh.pop();
			}

			if (i & 1)
				medians.push_back(mxh.top());
		}

		cout << medians.size() << '\n';
		for (int i = 0; i < medians.size(); i++) {
			cout << medians[i] << ' ';
			if ((i + 1) % 10 == 0 || i == medians.size() - 1)
				cout << '\n';
		}
	}
}