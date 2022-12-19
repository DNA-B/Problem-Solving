#include <bits/stdc++.h>

using namespace std;

int mem[1000001];
int a, k;

int make_k()
{
    for (int i = a + 1; i <= k; i++)
    {
        if (i % 2 == 0 && i / 2 >= a) // 만약 2를 곱할 수 있다면 최솟값 비교
            mem[i] = min(mem[i - 1], mem[i / 2]) + 1;
        else // i가 홀수일 경우 2를 곱해서 나올수 없으므로 그냥 mem[i - 1] + 1
            mem[i] = mem[i - 1] + 1;
    }

    return mem[k];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> a >> k;

    cout << make_k();

    return 0;
}