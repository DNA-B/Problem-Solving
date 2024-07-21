#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, n_six = 0, n_cur = 0;
    string tmp;

    cin >> n;

    while (n_six != n) {
        if (to_string(n_cur).find("666") != string::npos)
            n_six++;
        n_cur++;
    }

    cout << n_cur - 1;

    return 0;
}