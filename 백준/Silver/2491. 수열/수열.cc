#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N;
int arr[100001];
int increse[100001];
int decrese[100001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    increse[0] = decrese[0] = 1;
    for (int i = 1; i < N; i++) // increse
    {
        increse[i] = 1;

        if (arr[i - 1] <= arr[i])
            increse[i] = increse[i - 1] + 1;
    }

    for (int i = 1; i < N; i++) // decrese
    {
        decrese[i] = 1;

        if (arr[i - 1] >= arr[i])
            decrese[i] = decrese[i - 1] + 1;
    }

    int max_in = *max_element(increse, increse + N);
    int max_de = *max_element(decrese, decrese + N);

    cout << max(max_in, max_de);

    return 0;
}
