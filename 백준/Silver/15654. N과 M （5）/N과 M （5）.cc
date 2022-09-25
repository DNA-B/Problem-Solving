#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10]; // 수열 
int num[10];
bool isused[10001];

void func(int k) { // 현재 k개까지 수를 택했음.
    if (k == m) { // m개를 모두 택했으면
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' '; // arr 출력
        cout << '\n';
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!isused[num[i]])
        {
            arr[k] = num[i]; // 수열의 k번째 수를 i로 정함
            isused[num[i]] = true;
            func(k + 1); // 다음 수를 정하기 위해 func(k + 1) 호출
            isused[num[i]] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    sort(num, num + n);

    func(0);

    return 0;
}