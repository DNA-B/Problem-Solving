#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

int N;

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
       
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < ((N / 2) + (N % 2)); j++) // 몫 + 나머지
            cout << "* ";
        cout << "\n";

        for (int j = 0; j < (N / 2); j++) // 몫
            cout << " *";
        cout << "\n";
    }

    return 0;
}