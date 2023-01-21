#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int m, f;

    while (1) 
    {
        cin >> m >> f;

        if (m == 0 && f == 0)
            break;
        else
            cout << m + f << "\n";
    }


	return 0;
}