#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    if (n & 1) {
        for (int i = 1; i <= n; i++)
            if (i % 2 != 0) answer += i;
    }
    else {
        for (int i = 1; i <= n; i++)
            if (i % 2 == 0) answer += pow(i, 2);
    }
    
    return answer;
}