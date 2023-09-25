#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAX 4e9

using namespace std;

int N;
int arr[1001];
vector<int> diff;
int ans = -1;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    /* 
        (x + y + z = k)에서 두 수(x + y)의 합을 담은 diff 배열이 있을 때
        (diff + z = k)라면, (k - z = diff)이므로
        (k - z)가 diff 배열에 존재하는지 binary_search를 이용한다면
        O(N^2 * log(N)) 시간복잡도로 해결이 가능하다.
    */

    sort(arr, arr + N);
    for (int i = 0; i < N; i++) // diff 배열 생성
        for (int j = i; j < N; j++)
            diff.push_back(arr[i] + arr[j]);

    sort(diff.begin(), diff.end()); // binary_search 전 오름차순 정렬
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (binary_search(diff.begin(), diff.end(), arr[i] - arr[j])) // k - z가 diff 배열에 있다면
                ans = max(ans, arr[i]);

    cout << ans;

    return 0;
}
