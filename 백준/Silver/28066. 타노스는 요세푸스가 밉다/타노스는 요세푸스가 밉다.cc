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
int N, K, cnt = 0;
queue<int> q;
//=========================//


int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N >> K;

	for (int i = 1; i <= N; i++)
		q.push(i);

	while (q.size() > 1) {
		q.push(q.front()); // 첫 번째 수는 건너뛰고 뒤의 K - 1개 삭제
		q.pop();

		for (int i = 0; i < K - 1; i++) {
			if (q.size() == 1) break;
			if (!q.empty()) q.pop();
		}
	}

	cout << q.front();
}