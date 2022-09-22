#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
vector<pair<int, int>> v;

void hanoi(int n, int start, int dest)
{
    // n-1 원판을 시작과 끝이 아닌 판으로 옮기고, n을 끝으로 옮긴다.
    if (n == 1)
    {
        v.push_back({ start, dest });
        cnt++;
        return;
    }

    hanoi(n - 1, start, 6 - start - dest); // 1+2+3 = 6이니까 남은 판은 6-시작-끝
    v.push_back({start, dest});
    cnt++;
    hanoi(n - 1, 6 - start - dest, dest);
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;

    cin >> n;
    hanoi(n, 1, 3);

    cout << cnt << "\n";
    for (auto item : v)
    {
        cout << item.first << " " << item.second << "\n";
    }

    return 0;
}