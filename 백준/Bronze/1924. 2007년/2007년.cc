#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, d;
    cin >> m >> d;

    int month[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int days = 0;

    days += d;
    for (int i = 0; i < (m - 1); i++) 
    {
        days += month[i];
    }

    switch (days % 7) {
    case 0:
        cout << "SUN";
        break;
    case 1:
        cout << "MON";
        break;
    case 2:
        cout << "TUE";
        break;
    case 3:
        cout << "WED";
        break;
    case 4:
        cout << "THU";
        break;
    case 5:
        cout << "FRI";
        break;
    case 6:
        cout << "SAT";
        break;
    }

    return 0;
}