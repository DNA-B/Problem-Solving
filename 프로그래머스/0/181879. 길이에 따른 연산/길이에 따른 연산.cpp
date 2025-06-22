#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> num_list) {
    int answer = 0;
    
    if (num_list.size() >= 11) {
        answer = accumulate(num_list.begin(), num_list.end(), 0);
    } else {
        answer = accumulate(num_list.begin(), num_list.end(), 1, [](long long a, long long b) { return a * b; });
    }
    
    return answer;
}