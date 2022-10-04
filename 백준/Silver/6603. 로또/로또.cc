#include <bits/stdc++.h>

using namespace std;

int n = 1;
int arr[10];
int num[10];
bool isused[50];

void func(int k, int st)
{ // 현재 k개까지 수를 택했음.
    if (k == 6)
    {
        for (int i = 0; i < 6; ++i)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = st; i < n; i++) 
    {
        if (!isused[num[i]])
        {
            arr[k] = num[i];
            isused[num[i]] = true;
            func(k + 1, i + 1);
            isused[num[i]] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (n != 0)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            cin >> num[i];
        }
        sort(num, num + n);
        func(0, 0);

        cout << "\n";

        fill(num, num + 10, 0);
        fill(isused, isused + 50, false);
    }

    return 0;
}
