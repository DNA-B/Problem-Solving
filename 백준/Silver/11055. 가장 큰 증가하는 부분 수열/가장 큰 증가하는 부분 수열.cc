#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int arr[1001];
int mem[1001];
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    for (int i = 1; i <= N; i++)
    {
        mem[i] = arr[i];

        for (int j = 1; j < i; j++)
        {
            if (arr[j] < arr[i])
                mem[i] = max(mem[i], mem[j] + arr[i]);
        }
    }

    cout << *max_element(mem + 1, mem + (N + 1));

    return 0;
}
