#include <bits/stdc++.h>

using namespace std;

long long res = 0;

void babmukja(long long& want_what, long long& sick_what)
{
    if (want_what > 0 && sick_what > 0 && want_what > sick_what)
    {
        res += sick_what;
        want_what -= sick_what;
        sick_what = 0;
    }
    else if (want_what > 0 && sick_what > 0 && want_what <= sick_what)
    {
        res += want_what;
        sick_what -= want_what;
        want_what = 0;
    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long want_pizz, want_chic, want_hamb;
    long long sick_pizz, sick_chic, sick_hamb;


    cin >> want_chic >> want_pizz >> want_hamb;
    cin >> sick_chic >> sick_pizz >> sick_hamb;


    for (int i = 0; i < 1000; i++)
    {
        babmukja(want_chic, sick_chic);
        if (sick_chic >= 3)
        {
            sick_pizz += sick_chic / 3;
            sick_chic %= 3;
        }

        babmukja(want_pizz, sick_pizz);
        if (sick_pizz >= 3)
        {
            sick_hamb += sick_pizz / 3;
            sick_pizz %= 3;
        }

        babmukja(want_hamb, sick_hamb);
        if (sick_hamb >= 3)
        {
            sick_chic += sick_hamb / 3;
            sick_hamb %= 3;
        }
    }

    cout << res;

    return 0;
}