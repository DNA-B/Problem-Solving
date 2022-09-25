#include <bits/stdc++.h>

using namespace std;

bool isused1[40]; // 열
bool isused2[40]; // '/' 방향 대각선
bool isused3[40]; // '\' 방향 대각선

int cnt = 0;
int n;

void func(int cur) 
{ // cur번째 행에 말을 배치
    if (cur == n) 
    { // N개를 놓는데 성공했다면
        cnt++;
        return;
    }

    for (int i = 0; i < n; i++) 
    { // (cur, i) 좌표
        if (isused1[i] || isused2[cur + i] || isused3[(cur - i) + (n - 1)]) // 열이나 '/' '\' 대각선에 놓을 수 없다면
            continue;

        isused1[i] = true;
        isused2[cur + i] = true;
        isused3[(cur - i) + (n - 1)] = true;

        func(cur + 1);

        isused1[i] = false;
        isused2[cur + i] = false;
        isused3[(cur - i) + (n - 1)] = false;
    }
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    func(0);
    cout << cnt;
    return 0;
}