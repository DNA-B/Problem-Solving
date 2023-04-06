#include<bits/stdc++.h>

using namespace std;

int arr[100001];
int mem[100001];
int N;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    mem[0] = 0;

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        mem[i] = arr[i]; 
    }

    for (int i = 1; i <= N; i++)
        mem[i] = max(mem[i], mem[i - 1] + arr[i]); // 원래 수보다 합이 작다면 선택 초기화

    cout << *max_element(mem + 1, mem + N + 1);

    return 0;
}