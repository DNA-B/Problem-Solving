#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

string s;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> s;

    if (s == "SONGDO")
        cout << "HIGHSCHOOL";
    else if (s == "CODE")
        cout << "MASTER";
    else if (s == "2023")
        cout << "0611";
    else if (s == "ALGORITHM")
        cout << "CONTEST";

    return 0;
}