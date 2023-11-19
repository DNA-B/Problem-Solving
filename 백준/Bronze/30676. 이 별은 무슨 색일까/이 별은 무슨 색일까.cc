#include <bits/stdc++.h>

using namespace std;

int l;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> l;

    if (380 <= l && l < 425)
        cout << "Violet";
    else if (425 <= l && l < 450)
        cout << "Indigo";
    else if (450 <= l && l < 495)
        cout << "Blue";
    else if (495 <= l && l < 570)
        cout << "Green";
    else if (570 <= l && l < 590)
        cout << "Yellow";
    else if (590 <= l && l < 620)
        cout << "Orange";
    else if (620 <= l && l <= 780)
        cout << "Red";

    return 0;
}
