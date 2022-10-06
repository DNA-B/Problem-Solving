#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10]; // 수열 배열

void func(int k) { // 현재 k개까지 수를 택했음.
    if (k == m) { // m개를 모두 택했으면
        for (int i = 0; i < m; i++)
            cout << arr[i] << ' '; // arr 출력
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) 
    {
        if (k == 0)
        {
            arr[k] = i;
            func(k + 1);
        }
        else if (arr[k - 1] <= i)
        { // 사용할 수 있으면서 비내림차일 경우
            arr[k] = i; // 수열의 k번째 수를 i로 정함
            func(k + 1); // 다음 수를 정하기 위해 func(k + 1) 호출
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    func(0);

    return 0;
}