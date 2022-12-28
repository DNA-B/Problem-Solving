#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int antenna, eyes;

    cin >> antenna >>  eyes;

    if (antenna >= 3 && eyes <= 4)
        cout << "TroyMartian" << "\n";

    if (antenna <= 6 && eyes >= 2)
        cout << "VladSaturnian" << "\n";

    if (antenna <= 2 && eyes <= 3)
        cout << "GraemeMercurian" << "\n";

    return 0;
}