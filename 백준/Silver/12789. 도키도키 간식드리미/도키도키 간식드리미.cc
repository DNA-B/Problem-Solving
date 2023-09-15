#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N;
int cur = 1;
int arr[1001];
stack<int> st;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int idx = 0;
    while (idx != N)
    {
        if (cur == arr[idx])
        {
            cur++;
            idx++;
        }
        else if (!st.empty() && cur == st.top())
        {
            st.pop();
            cur++;
        }
        else
        {
            st.push(arr[idx]);
            idx++;
        }
    }

    while (!st.empty())
    {
        if (cur == st.top())
            cur++;

        st.pop();
    }

    if (cur == N + 1)
        cout << "Nice";
    else
        cout << "Sad";

    return 0;
}
