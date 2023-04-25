#include<bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string name;

    cin >> name;

    if (name == "NLCS")
        cout << "North London Collegiate School";
    else if (name == "BHA")
        cout << "Branksome Hall Asia";
    else if (name == "KIS")
        cout << "Korea International School";
    else if (name == "SJA")
        cout << "St. Johnsbury Academy";
    

    return 0;
}