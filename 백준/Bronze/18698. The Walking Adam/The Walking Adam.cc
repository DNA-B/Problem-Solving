#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

    int n, result = 0;
    string t;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t;
        for (int j = 0; j < t.size(); j++) {
            if (t[j] == 'U')
                result++;
            else
                break;
        }
        cout << result << endl;
        result = 0;
    }

	return 0;
}