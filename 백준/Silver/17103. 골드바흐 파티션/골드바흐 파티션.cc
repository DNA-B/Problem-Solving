#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 1000000

using namespace std;

int T;
int prime_number[MAX + 1];

void era()
{
    for (int i = 2; i <= sqrt(MAX); i++)
    {
        if (prime_number[i] == -1)
            continue;


        for (int j = i * i; j <= MAX; j += i)
            prime_number[j] = -1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;

    for (int i = 2; i <= MAX; i++)
        prime_number[i] = i;

    era();

    while (T--)
    {
        int n;
        int cnt = 0;

        cin >> n;

        for (int i = 2; i < n; i++)
        {
            if (prime_number[i] != -1 && prime_number[n - i] != -1)
            {
                cnt++;

                if (n - i == i) // 마지막에 (cnt / 2) 고려
                    cnt++;
            }
        }
        cout << cnt / 2 << "\n";
    }

    return 0;
}
