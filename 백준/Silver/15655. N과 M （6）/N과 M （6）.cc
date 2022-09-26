#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    int arr[8];
    vector<int> v;

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        v.push_back(i < m ? 0 : 1);
    }
        
    sort(arr, arr + n);

    do {
        for (int i = 0; i < n; ++i)
            if (v[i] == 0) // next_permutation은 오름차순 정렬된 상태에서 실행되므로 1로하면 내림차순으로 나온다.
                cout << arr[i] << ' ';
        cout << '\n';
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}