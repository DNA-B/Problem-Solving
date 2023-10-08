#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

long long mem[600001];

int solution(int n) {
    int answer = 0;

    mem[1] = 1;
    mem[2] = 2;

    for (int i = 3; i <= n; i++)
        mem[i] = (mem[i - 2] % MOD)+ (mem[i - 1] % MOD);   

    answer = mem[n] % MOD;

    return answer;
}