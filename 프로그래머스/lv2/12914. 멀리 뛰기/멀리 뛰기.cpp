#include <string>
#include <vector>

using namespace std;

long long mem[2001];
int dest;

int dp(int n)
{
    if(n == 1)
        return 1;
    else if(n == 2)
        return 2;
    
    if(mem[n] != 0)
        return mem[n] % 1234567;
    
    mem[n] = (dp(n - 1) % 1234567) + (dp(n - 2) % 1234567);
    return mem[n] % 1234567;
}

long long solution(int n) {
    long long answer = 0;
    dest = n;
    
    answer = dp(n) % 1234567;
    
    return answer;
}