#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int test, test1;
    cin >> test >> test1;

    string str;
    vector<string> v;

    for (int i = 0; i < test; i++) {
        cin >> str;
        v.push_back(str);
    }

    for (int i = 0; i < test; i++) {
        // key point
        reverse(v[i].begin(), v[i].end());
        cout << v[i] << "\n";
    }

	return 0;
}