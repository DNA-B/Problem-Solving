#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N, K;
int cnt = 0;
int arr[500001];
int tmp[500001];

void merge_sort(int p, int r);
void merge(int p, int q, int r);

void merge_sort(int p, int r)
{
    int q;

    if (p < r)
    {
        q = (p + r) / 2;
        merge_sort(p, q);
        merge_sort(q + 1, r);
        merge(p, q, r);
    }
}

void merge(int p, int q, int r)
{
    int i = p;
    int j = q + 1;
    int t = 1;

    while (i <= q && j <= r)
    {
        if (arr[i] <= arr[j])
            tmp[t++] = arr[i++];
        else
            tmp[t++] = arr[j++];
    }

    while (i <= q)
        tmp[t++] = arr[i++];

    while (j <= r)
        tmp[t++] = arr[j++];

    i = p;
    t = 1;

    while (i <= r)
    {
        cnt++;

        if (cnt == K)
        {
            cout << tmp[t];
            exit(0);
        }

        arr[i++] = tmp[t++];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    merge_sort(0, N - 1);
    
    cout << -1; // 저장 횟수가 K보다 작은 경우

    return 0;
}
