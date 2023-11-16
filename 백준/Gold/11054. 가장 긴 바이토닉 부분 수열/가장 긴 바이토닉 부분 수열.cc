#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 100000000

using namespace std;

int N;
int ans = -1;
int arr[1001];
vector<int> increse;
vector<int> decrese;

int bitonic(int idx)
{
    for (int i = 0; i <= idx; i++)
    {
        if (increse.empty() || increse.back() < arr[i])
            increse.push_back(arr[i]);
        else
            *lower_bound(increse.begin(), increse.end(), arr[i]) = arr[i];
    }

    for (int i = idx; i < N; i++)
    {
        if (decrese.empty() || decrese.back() > arr[i])
            decrese.push_back(arr[i]);
        else
            *lower_bound(decrese.begin(), decrese.end(), arr[i], greater<>()) = arr[i];
    }

    increse.insert(increse.end(), decrese.begin() + 1, decrese.end());
    return increse.size();
}



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N; i++)
    {
        increse.clear();
        decrese.clear();
        
        ans = max(ans, bitonic(i));
    }

    cout << ans;

    return 0;
}
