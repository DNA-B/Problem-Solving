#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int q, l, r;
char alp;
string s = "0", tmp;
int arr[26][200002];

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tmp >> q;

    s += tmp;
    for (int i = 1; i < s.length(); i++) 
    {
        for (int j = 0; j < 26; j++)
        {
            if ((s[i] - 'a') == j)
                arr[j][i] = arr[j][i - 1] + 1;
            else
                arr[j][i] = arr[j][i - 1];
        }
    }

    while (q--)
    {
        cin >> alp >> l >> r;
        cout << arr[alp - 'a'][r + 1] - arr[alp - 'a'][l] << "\n";
    }

    return 0;
}