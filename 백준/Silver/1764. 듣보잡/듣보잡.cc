#include <bits/stdc++.h>
#define IO ios::sync_with_stdio(0); cin.tie(0);
using namespace std;


int main() 
{
    IO;
    
    set<string> s;
    set<string> res;
    auto iter = s.begin();
    string people;
    int d, b;
    int count = 0;

    cin >> d >> b;

    while (d--)
    {
        cin >> people;
        s.insert(people);
    }

    while (b--)
    {
        cin >> people;
        iter = s.find(people);
        if (!(iter == s.end()))
        {
            count++;
            res.insert(people);
        }
    }

    iter = res.begin();

    cout << count << "\n";
    for (auto str : res)
    {
        cout << str << "\n";
    }

    return 0;
}