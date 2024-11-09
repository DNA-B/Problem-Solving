#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 123456789

using namespace std;

int M, N;
int mem[1000001];
bool is_not_prime[1000001];

void era() {
    is_not_prime[1] = true;
    
    for (int i = 2; i <= sqrt(N); i++) {
        if (is_not_prime[i] == true)
            continue;
        for (int j = i * i; j <= N; j += i)
            is_not_prime[j] = true;
    }
    
    for (int i = M; i <= N; i++) {
        if (is_not_prime[i] == false)
            cout << i << "\n";
    }
}

int main(void) {
    cin.tie(0)->ios::sync_with_stdio(0);
    
    cin >> M >> N;
    era();

    return 0;
}