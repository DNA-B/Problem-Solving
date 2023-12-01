#include <bits/stdc++.h>

using namespace std;

int N;
int ans = 0;
string str;
set<string> s;

bool is_prime(int n)
{
    if (n == 1)
        return false;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

bool is_suprise(string n)
{
    for (int i = 1; i < n.size(); i++) // N자리는 검사했으므로 N-1자리까지만 검사
    {
        int tmp = stoi(n.substr(0, i));

        if (!is_prime(tmp))
            return false;
    }

    return true;
}

void backtracking(int cur)
{
    if (cur == N)
    {
        if (is_suprise(str))
            s.insert(str);

        return;
    }

    for (int i = 1; i < 10; i++)
    {
        str += i + '0';

        if (is_prime(stoi(str)))
            backtracking(cur + 1);

        str.pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    backtracking(0);

    for (auto item : s)
        cout << item << "\n";

    return 0;
}
