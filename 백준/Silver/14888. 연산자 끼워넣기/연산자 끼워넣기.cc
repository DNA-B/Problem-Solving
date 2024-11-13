#include <bits/stdc++.h>

using namespace std;

/*
BOJ 14888 : 연산자 끼워넣기
- N의 크기가 11로 매우 작다.
- 모든 순열을 다 찾는다고 하면 (N-1)!이다.
- O(N * (N-1)!)이라고 해도 N이 작으므로 2초안에 가능할 것이다.
- 연산자를 담은 배열에서 next_permutation을 통해 순열을 구하고 최댓값, 최솟값을 계속 갱신하여 준다.
*/

int n, num_op;
int res_min = 2100000000, res_max = -2100000000;
vector<char> v_op;
vector<int> v;

int main() {
    cin.tie(0)->ios::sync_with_stdio(0);

    cin >> n;
    v.resize(n);

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    for (int i = 0; i < 4; i++) {
        cin >> num_op;

        switch (i) {
        case 0:
            while (num_op--)
                v_op.push_back('+');
            break;
        case 1:
            while (num_op--)
                v_op.push_back('-');
            break;
        case 2:
            while (num_op--)
                v_op.push_back('x');
            break;
        case 3:
            while (num_op--)
                v_op.push_back('/');
            break;
        }
    }

    sort(v_op.begin(), v_op.end());

    do {
        int tmp = v[0];

        for (int i = 1; i < n; i++) {
            switch (v_op[i - 1]) {
            case '+':
                tmp += v[i];
                break;
            case '-':
                tmp -= v[i];
                break;
            case 'x':
                tmp *= v[i];
                break;
            case '/':
                tmp /= v[i];
                break;
            }
        }

        if (res_max < tmp)
            res_max = tmp;

        if (res_min > tmp)
            res_min = tmp;

    } while (next_permutation(v_op.begin(), v_op.end()));

    cout << res_max << "\n" << res_min;
    return 0;
}