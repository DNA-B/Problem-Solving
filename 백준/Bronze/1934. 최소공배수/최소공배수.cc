#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    int a, b, c;
    int tmp_a, tmp_b;

    cin >> t;

    while (t--)
    {
        cin >> a >> b;
        
        tmp_a = a;
        tmp_b = b;

        while (tmp_b != 0)
        {
            c = tmp_a % tmp_b;
            tmp_a = tmp_b;
            tmp_b = c;
        }
        
        cout << (a * b) / tmp_a << "\n";
    }
    

	return 0;
}