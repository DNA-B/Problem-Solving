#include <string>
#include <vector>
#define MOD 1000000007

using namespace std;

long long mem[5001];

int solution(int n) {
    int answer = 0;
    
    if (n % 2 != 0)
        return 0;
    
    mem[2] = 3;
    mem[4] = 11;

    for (int i = 6; i <= n; i += 2)
    {
        mem[i] = (mem[i - 2] * 3) % MOD; // 바로 전 크기에 3x2 타일 붙이기

        for (int j = i - 4; j >= 2; j -= 2) // 특이 3x4 특이 타일
            mem[i] += (mem[j] * 2) % MOD;

        mem[i] = (mem[i] + 2) % MOD; // i번째 크기의 특이타일 2개
    }

    answer = mem[n] % MOD;
    
    return answer;
}