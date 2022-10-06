#include <bits/stdc++.h>

using namespace std;

int main()
{
    int sh, sm, ss, eh, em, es;
    int start, end, t, h, m, s;
    for(int i = 0; i < 3; i++)
    {
        cin >> sh >> sm >> ss >> eh >> em >> es;
        start = (sh*3600) + (sm*60) + ss;
        end = (eh*3600) + (em*60) + es;
        t = end - start;
        h = t / 3600;
        m = (t % 3600) / 60;
        s = (t % 3600) % 60;
        
        cout << h << " " << m <<" " << s << "\n";
    }
    return 0;
}