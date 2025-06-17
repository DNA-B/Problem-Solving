#include <string>
#include <vector>

using namespace std;

vector<int> solution(string my_string) {
    vector<int> answer(52, 0);
    
    for (char ch : my_string) {
        if (isupper(ch))
            answer[ch - 'A']++;
        else
            answer[ch - 'a' + 26]++;
    }
    
    return answer;
}