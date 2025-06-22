#include <string>
#include <vector>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    
    string tmp = "";
    for (int i = 0; i < my_string.length(); i++) {
        if (my_string[i] == ' ') {
            answer.push_back(tmp);
            tmp = "";
            continue;
        }
        
        tmp += my_string[i];
    }
        
    answer.push_back(tmp);
    return answer;
}