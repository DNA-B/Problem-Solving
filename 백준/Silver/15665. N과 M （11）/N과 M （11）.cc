#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
int num[10];

void func(int k)
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

    int tmp = 0;  // 중복 수열 확인 변수

    for (int i = 0; i < n; ++i)
    {
        if (tmp != num[i])
        { // 이전 수열의 마지막 항과 새로운 수열의 마지막 항이 같으면 중복 수열
            arr[k] = num[i];
            tmp = arr[k];
            func(k + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        cin >> num[i];

    sort(num, num + n);
    func(0);

    return 0;
}
