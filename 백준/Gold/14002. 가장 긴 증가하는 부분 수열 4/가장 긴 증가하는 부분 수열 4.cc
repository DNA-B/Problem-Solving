#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int arr[1001];
vector<pair<int, int>> mem(1001); // {길이, 자식};
vector<int> path;
int N;

void find_path(int cur, int child)
{
    if (cur == child)
    {
        path.push_back(arr[cur]);
        return;
    }

    find_path(child, mem[child].second);
    path.push_back(arr[cur]);

    return;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N; i++)
    {
        mem[i] = {1, i};

        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                if (mem[i].first < mem[j].first + 1)
                {
                    mem[i].first = mem[j].first + 1;
                    mem[i].second = j;
                }
            }
        }
    }

    int idx = max_element(mem.begin(), mem.end()) - mem.begin();
    find_path(idx, mem[idx].second);

    cout << mem[idx].first << "\n";
    for (int item : path)
        cout << item << " ";

    return 0;
}
