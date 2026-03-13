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
int N;
string trash[10005];
int costs[7] = { 0, };
//=========================//

int main() {
	cin.tie(nullptr)->ios_base::sync_with_stdio(false);
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> trash[i];

	for (int i = 0; i < 7; i++)
		cin >> costs[i]; // P, C, V, S, G, F, O

	ll min_value = 0;
	for (int i = 0; i < N; i++) {
		int cnt_p = 0, cnt_c = 0, cnt_v = 0, cnt_s = 0, cnt_g = 0, cnt_f = 0, cnt_o = 0;
		for (char t : trash[i]) {
			switch (t) {
			case 'P':
				cnt_p++;
				break;
			case 'C':
				cnt_c++;
				break;
			case 'V':
				cnt_v++;
				break;
			case 'S':
				cnt_s++;
				break;
			case 'G':
				cnt_g++;
				break;
			case 'F':
				cnt_f++;
				break;
			case 'O':
				cnt_o++;
				break;
			}
		}

		ll len = trash[i].length();

		if (cnt_p == len)
			min_value += trash[i].length() * min(costs[0], costs[6]);
		else if (cnt_c == len)
			min_value += trash[i].length() * min(costs[1], costs[6]);
		else if (cnt_v == len)
			min_value += trash[i].length() * min(costs[2], costs[6]);
		else if (cnt_s == len)
			min_value += trash[i].length() * min(costs[3], costs[6]);
		else if (cnt_g == len)
			min_value += trash[i].length() * min(costs[4], costs[6]);
		else if (cnt_f == len)
			min_value += trash[i].length() * min(costs[5], costs[6]);
		else // not recycle
			min_value += trash[i].length() * costs[6];
	}

	cout << min_value;
}