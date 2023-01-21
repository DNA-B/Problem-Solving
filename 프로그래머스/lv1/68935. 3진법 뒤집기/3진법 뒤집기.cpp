#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    string tmp = "";
    
    while(n >= 3)
    {
        tmp += to_string(n % 3);
        n /= 3;
    }
    
    tmp += to_string(n);
    
    for(int i = 0;i<tmp.length();i++)
        answer += (tmp[tmp.length() - (i + 1)] - '0') * (long long)pow(3, i);

    return answer;
}