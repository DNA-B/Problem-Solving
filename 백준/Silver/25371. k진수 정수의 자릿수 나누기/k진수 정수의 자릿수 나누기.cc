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
ll N, K, i, sum = 0, num = 0;
stack<ll> s;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG
    


	cin >> N >> K;
	while (N) {
		s.push(N % K);
		N /= K;
	}
	while (s.size()) {
		if (s.top() == 0) {
			sum += num;
			num = 0;
		}
		else {
			num *= 10;
			num += s.top();
		}
		s.pop();
	}
	sum += num;

	N = sum;
	while (N) {
		s.push(N % K);
		N /= K;
	}
	while (s.size()) {
		cout << s.top();
		s.pop();
	}
}