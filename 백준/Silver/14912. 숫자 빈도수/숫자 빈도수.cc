#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N, D;
int freq[10];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> D;

    for (int i = 1; i <= N; i++)
    {
        string tmp = to_string(i);

        for (char ch : tmp)
            freq[ch - '0']++;
    }

    cout << freq[D];

    return 0;
}
