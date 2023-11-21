#include <bits/stdc++.h>

using namespace std;

int N, L;
vector<string> v;
string tmp, word;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    cin.ignore();

    for (int i = 1; i <= N; i++)
    {
        v.clear();
        getline(cin, tmp);

        stringstream ss(tmp);

        while (getline(ss, word, ' '))
            v.push_back(word);

        cout << "Case #" << i << ": ";
        for (int i = v.size() - 1; i >= 0; i--)
            cout << v[i] << " ";
        cout << "\n";
    }

    return 0;
}
