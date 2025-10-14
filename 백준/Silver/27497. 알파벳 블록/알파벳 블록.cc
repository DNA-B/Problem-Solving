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
int N, order;
char ch;
stack<int> orders;
deque<char> S;
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	while (N--) {
		cin >> order;

		if (order == 1 || order == 2)
			orders.push(order);

		switch (order) {
			case 1:
				cin >> ch;
				S.push_back(ch);
				break;
			case 2:
				cin >> ch;
				S.push_front(ch);
				break;
			case 3:
				if (!S.empty() && !orders.empty()) {
					int dir = orders.top();
					orders.pop();
					if (dir == 1)
						S.pop_back();
					else
						S.pop_front();
				}
				break;
		}
	}

	cout << (S.empty() ? "0" : string(S.begin(), S.end())) << "\n";
}