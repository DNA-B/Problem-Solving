#include <bits/stdc++.h>
#define INF 0x3f3f3f3f

using namespace std;

int N_A, N_B;
set<int> A;
set<int> B;
vector<int> diff(400002);

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N_A >> N_B;

    while (N_A--)
    {
        int x;

        cin >> x;
        A.insert(x);
    }

    while (N_B--)
    {
        int x;

        cin >> x;
        B.insert(x);
    }

    auto it = set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), diff.begin());
    diff.resize(it - diff.begin());

    cout << diff.size();

    return 0;
}
