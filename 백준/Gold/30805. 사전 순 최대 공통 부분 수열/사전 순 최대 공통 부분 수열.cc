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
int A[105], B[105];
vector<tuple<int, int, int>> seq;
vector<int> res;
//=========================//

bool cmp(tuple<int, int, int>& a, tuple<int, int, int>& b) {
	auto [v1, x1, y1] = a;
	auto [v2, x2, y2] = b;

	if (v1 == v2) { // 값이 같으면 인덱스 작은게 앞으로
		if (x1 == x2)
			return y1 < y2;
		return x1 < x2;
	}

	return v1 > v2; // 기본은 값 기준 내림차순 정렬
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];

	cin >> M;
	for (int i = 0; i < M; i++)
		cin >> B[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i] == B[j])
				seq.push_back({ A[i], i, j });
		}
	}

	sort(seq.begin(), seq.end(), cmp);

	int i = -1, j = -1;
	for (auto& [v, x, y] : seq) {
		if (x > i && y > j) {
			res.push_back(v);
			i = x;
			j = y;
		}
	}

	cout << res.size() << '\n';
	for (int& v : res)
		cout << v << ' ';
}