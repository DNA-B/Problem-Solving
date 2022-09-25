#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string str = to_string(n);
    int len = str.length();
    
    for(int i = len - 1; i >= 0 ; i--)
    {
        answer.push_back(str[i] - '0');
    }
    
    return answer;
}