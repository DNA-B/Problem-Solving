#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int hour, minute, time;

    cin >> hour >> minute;
    cin >> time;

    minute += time;
    hour += minute / 60;

    if (hour > 23)
        hour -= 24;

    if (minute > 59)
        minute %= 60;
                

    cout << hour << " " << minute;

    return 0;
}