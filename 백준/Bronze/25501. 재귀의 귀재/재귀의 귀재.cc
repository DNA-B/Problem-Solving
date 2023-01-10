#include <bits/stdc++.h>

using namespace std;

int cnt = 1;

int recursion(const char* str, int l, int r) 
{
    if (l >= r)
        return 1;
    else if (str[l] != str[r])
        return 0;
    else
    {
        cnt++;
        return recursion(str, l + 1, r - 1);
    }
}

int isPalindrome(const char* str) 
{
    return recursion(str, 0, strlen(str) - 1);
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    int t;
    char str[1001] = { '\n' };

    cin >> t;

    while (t--)
    {
        cin >> str;
        cout << isPalindrome(str) << " ";
        cout << cnt << "\n";
        cnt = 1;
    }

    return 0;
}