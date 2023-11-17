#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 10000000

using namespace std;

int A, B;

bool is_prime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
}

bool is_palindrome(int n)
{
    string pre, post;

    pre = post = to_string(n);
    reverse(post.begin(), post.end());

    if (pre == post)
        return true;
    else
        return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> A >> B;

    if (B >= MAX)
        B = MAX;

    for (int i = A; i <= B; i++)
    {
        if (is_palindrome(i) && is_prime(i))
            cout << i << "\n";
    }

    cout << "-1";

    return 0;
}
