#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    string u, v, ans;
    cin >> u;
    v = u;
    u += "0000";
    int c = 0;
    while (!v.empty()) {
        int val = u.back() + v.back() - 48 * 2 + c;
        c = val / 2;
        ans += to_string(val % 2);
        u.pop_back();
        v.pop_back();
    }
    while (!u.empty()) {
        int val = u.back() - 48 + c;
        c = val / 2;
        ans += to_string(val % 2);
        u.pop_back();
    }
    if (c) ans += "1";
    reverse(ans.begin(), ans.end());
    cout << ans;

	return 0;
}