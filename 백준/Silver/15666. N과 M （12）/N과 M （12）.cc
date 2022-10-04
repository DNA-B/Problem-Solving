#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
int num[10];
bool isin[10001];

void func(int k, int st)
{ // 현재 k개까지 수를 택했음.
    if (k == m)
    {
        for (int i = 0; i < m; ++i)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    int tmp = 0;

    for (int i = st; i < n; i++) 
    {
        if (num[i] != tmp) 
        {
            arr[k] = num[i];
            tmp = arr[k];
            func(k + 1, i); // 수를 결정한 시기의 i를 넘기면 자동으로 비내림차가 된다.
                            // 중복이 가능하므로 i + 1이 아닌 i를 넘긴다.
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
    {
        cin >> num[i];
    }

    sort(num, num + n);
    func(0, 0);

    return 0;
}
