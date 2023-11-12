#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N, K, cnt = 0;
int A[500001];

void merge(int st, int ed, int mid)
{
    int tmp[500001];
    int l = st;
    int r = mid + 1;
    int idx = st;

    while (l <= mid && r <= ed)
    {
        if (A[l] < A[r])
            tmp[idx++] = A[l++];
        else
            tmp[idx++] = A[r++];
    }

    while (l <= mid)
        tmp[idx++] = A[l++];

    while (r <= ed)
        tmp[idx++] = A[r++];

    for (int i = st; i <= ed; i++)
    {
        A[i] = tmp[i];
        cnt++;

        if (cnt == K)
        {
            for (int i = 0; i < N; i++)
                cout << A[i] << " ";

            exit(0);
        }
    }
}

void merge_sort(int st, int ed)
{
    if (st >= ed)
        return;

    int mid = (st + ed) / 2;

    merge_sort(st, mid);
    merge_sort(mid + 1, ed);
    merge(st, ed, mid);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    cin >> N >> K;
    int num;

    for (int i = 0; i < N; i++)
        cin >> A[i];

    merge_sort(0, N - 1);

    if (cnt < K)
        cout << -1;
}
