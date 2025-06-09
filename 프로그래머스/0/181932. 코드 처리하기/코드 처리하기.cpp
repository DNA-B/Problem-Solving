#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    string answer = "";
    
    bool mode = false;
    for (int i = 0; i < code.length(); i++) {
        if (!mode && code[i] != '1' && !(i & 1))
            answer += code[i];
        else if (!mode && code[i] == '1') 
            mode = true;
        else if (mode && code[i] != '1' && (i & 1))
            answer += code[i];
        else if (mode && code[i] == '1')
            mode = false;
    }

    if (answer.empty())
        answer = "EMPTY";

    return answer;
}