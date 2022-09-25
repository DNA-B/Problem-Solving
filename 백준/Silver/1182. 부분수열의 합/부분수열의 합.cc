#include <bits/stdc++.h>

using namespace std;

int n, s;
int arr[21];
int cnt = 0;

void func(int cur, int sum)
{
    if (cur == n)
    { // 모든 수의 포함 여부를 결정하고
        if (sum == s)
        { // 합이 s라면
            cnt++;
        }
        return;
    }

    func(cur + 1, sum); // 부분집합에 포함시키지 않았을 때
    func(cur + 1, sum + arr[cur]); // 부분집합에 포함시켰을 때
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    func(0, 0);

    if (s == 0) // 부분집합의 크기는 양수라 했으므로 s가 0일 때 카운팅되는 공집합은 제외한다.
        cnt--;

    cout << cnt;

    return 0;
}