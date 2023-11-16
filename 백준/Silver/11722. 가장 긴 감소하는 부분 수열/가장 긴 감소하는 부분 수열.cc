#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 100000000

using namespace std;

int N;
int arr[1001];
vector<int> mem;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N; i++)
    {
        if (mem.empty() || mem.back() > arr[i])
            mem.emplace_back(arr[i]);
        else
            *lower_bound(mem.begin(), mem.end(), arr[i], greater<>()) = arr[i];
    }

    cout << mem.size();

    return 0;
}
