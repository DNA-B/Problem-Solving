#include <bits/stdc++.h>

using namespace std;

vector<int> v;
int n, m;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    // m의 개수만큼 0을 넣어줌 nCm (0이 곧 선택 할 개수)
    for (int i = 0; i < n; ++i)  
        v.push_back(i < m ? 0 : 1);

    do {
        for (int i = 0; i < n; ++i)
            if (v[i] == 0) // next_permutation은 오름차순 정렬된 상태에서 실행되므로 1로하면 내림차순으로 나온다.
                cout << i + 1 << ' ';
        cout << '\n';
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}