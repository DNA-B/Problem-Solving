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
int N, M, res = 0;
deque<int> ne, po;
//=========================//

void last_books(bool mode) {
	int cnt = 0;
	if (mode) {
		res = abs(ne.front());
		for (int i = 0; i < M && !ne.empty(); i++) ne.pop_front();
	}
	else {
		res = po.back();
		for (int i = 0; i < M && !po.empty(); i++) po.pop_back();
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int x, i = 0; i < N; i++) {
		cin >> x;
		if (x > 0) po.push_back(x);
		else ne.push_back(x);
	}

	sort(po.begin(), po.end());
	sort(ne.begin(), ne.end());
	last_books(!ne.empty() && (po.empty() || abs(ne.front()) > po.back()));

	while (!ne.empty()) {
		vector<int> books;
		while (!ne.empty() && books.size() != M) {
			books.push_back(ne.front()); 
			ne.pop_front();
		}
		res += 2 * abs(books.front());
	}

	while (!po.empty()) {
		vector<int> books;
		while (!po.empty() && books.size() != M) {
			books.push_back(po.back()); 
			po.pop_back();
		}
		res += 2 * books.front();
	}

	cout << res;
}