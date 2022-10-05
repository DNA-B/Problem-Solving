#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n = 0;

    cin >> n;

    cout << "int a;\n";
    cout << "int *ptr = &a;\n";
    
    if (n == 1)
        return 0;
    
    for (int i = 1; i < n; i++)
    {
        cout << "int ";
        for (int j = 0; j <= i; j++)
        {
            cout << '*';
        }
        if (i == 1)
        {
            cout << "ptr" << i + 1 << " = &ptr" << "; \n";
        }
        else
        {
            cout << "ptr" << i + 1 << " = &ptr" << i << "; \n";
        }
    }
    return 0;
}