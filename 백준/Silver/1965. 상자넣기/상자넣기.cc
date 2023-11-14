#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N;
int arr[100001];
vector<int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    for (int i = 0; i < N; i++)
    {
        if (v.empty() || v.back() < arr[i])
            v.push_back(arr[i]);
        else
            *lower_bound(v.begin(), v.end(), arr[i]) = arr[i];
    }

    cout << v.size();

    return 0;
}
