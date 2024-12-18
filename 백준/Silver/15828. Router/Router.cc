#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_map>
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
int N, x;
queue<int> q;
//=========================//

void print_q() {
	while (!q.empty()) {
		cout << q.front() << ' ';
		q.pop();
	}
}

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
// 	freopen("input.txt", "r", stdin);

	cin >> N;

	while (cin >> x) {
		if (x == -1) break;
		if (x == 0) q.pop();
		else if (q.size() < N) q.push(x);
	}

	if (q.empty())
		cout << "empty";
	else
		print_q();
}