#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    int cur_give = 0;
    
    while(n >= a)
    {
        answer += b * (n / a);
        cur_give = b * (n / a);
        n -= a * (n / a);
        n += cur_give;
    }

    return answer;
}