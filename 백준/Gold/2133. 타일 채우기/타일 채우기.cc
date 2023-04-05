#include<bits/stdc++.h>

using namespace std;

int mem[31];
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    if (N % 2 != 0)
    {
        cout << 0;
        return 0;
    }

    mem[2] = 3;
    mem[4] = 11;

    for (int i = 6; i <= N; i += 2)
    {
        mem[i] = mem[i - 2] * 3; // 바로 전 크기에 3x2 타일 붙이기

        for (int j = i - 4; j >= 2; j -= 2) // 특이 3x4 특이 타일
            mem[i] += mem[j] * 2;

        mem[i] += 2; // i번째 크기의 특이타일 2개
    }

    cout << mem[N];

    return 0;
}