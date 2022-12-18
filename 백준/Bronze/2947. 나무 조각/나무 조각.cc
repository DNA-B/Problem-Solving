#include <bits/stdc++.h>

using namespace std;

vector <char> v(5);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 5; i++)
    {
        cin >> v[i];
    }
    
    while (string(v.begin(), v.end()) != "12345")
    {
        for (int j = 0; j < 4; j++)
        {
            if (v[j] - '0' > v[j + 1] - '0')
            {
                swap(v[j], v[j + 1]);

                for (int i = 0; i < 5; i++)
                    cout << v[i] << " ";
                cout << "\n";
            }
        }
    }

    return 0;
}