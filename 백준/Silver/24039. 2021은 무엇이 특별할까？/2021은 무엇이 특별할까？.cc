#include <bits/stdc++.h>

using namespace std;

/*
BOJ 24039 : 2021은 무엇이 특별할까?
그냥 에라토스테네스 -> 연속된 두 소수 찾기
*/

bool arr[100001];

void era(int n)
{
    arr[0] = true;
    arr[1] = true;

    for (int i = 2; i < sqrt(n); i++)
    {
        if (arr[i] == true)
            continue;

        for (int j = i + i; j <= n; j += i)
            arr[j] = true;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int year;

    cin >> year;

    era(100000);

    for (int i = 2; i < 10001; i++)
    {
        if (arr[i] == false)
        {
            int j = i + 1;
            
            while (arr[j] != false)
                j++;

            if (i * j > year)
            {
                cout << i * j;
                return 0;
            }
        }
        
    }

    return 0;
}