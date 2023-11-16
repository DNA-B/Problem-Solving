#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 100000000

using namespace std;

int N;
int ans = -1;
int arr[1001];
int increse[1001];
int decrese[1001];
int bitonic[1001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N; i++) // 증가 수열
    {
        increse[i] = 1;

        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                increse[i] = max(increse[i], increse[j] + 1);
        }
    }

    for (int i = N - 1; i >= 0; i--) // 감소 수열
    {
        decrese[i] = 1;

        for (int j = N - 1; j > i; j--)
        {
            if (arr[j] < arr[i])
                decrese[i] = max(decrese[i], decrese[j] + 1);
        }
    }

    for (int i = 0; i < N; i++)
        bitonic[i] = increse[i] + decrese[i];

    cout << *max_element(bitonic, bitonic + N) - 1; // K번째 중복 빼주기

    return 0;
}
