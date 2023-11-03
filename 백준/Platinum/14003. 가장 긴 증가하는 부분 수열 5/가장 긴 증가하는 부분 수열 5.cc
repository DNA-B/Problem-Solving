#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N;
int arr[1000001];
int mem[1000001];
vector<int> v;
stack<int> st;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N; i++)
    {
        if (v.empty() || arr[i] > v.back())
        {
            v.push_back(arr[i]);
            mem[i] = v.size();
        }
        else
        {
            auto it = lower_bound(v.begin(), v.end(), arr[i]);
            *it = arr[i];
            mem[i] = (it - v.begin()) + 1;
        }
    }

    int idx = max_element(mem, mem + N) - mem;
    st.push(arr[idx]);

    for (int i = idx; i >= 0; i--)
    {
        if (mem[i] == mem[idx] - 1)
        {
            st.push(arr[i]);
            idx = i;
        }
    }

    cout << v.size() << "\n";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
