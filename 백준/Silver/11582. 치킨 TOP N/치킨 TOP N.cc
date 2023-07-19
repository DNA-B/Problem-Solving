#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N, K;
int arr[1050000];
int sort_people, repeat;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    cin >> K;

    sort_people = N / 2;
    repeat = N / sort_people;
    while (sort_people != K / 2)
    {
        for (int i = 0; i < N; i += repeat)
            sort(arr + i, arr + i + repeat);

        sort_people /= 2;
        repeat = N / sort_people;
    }

    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";

    return 0;
}
