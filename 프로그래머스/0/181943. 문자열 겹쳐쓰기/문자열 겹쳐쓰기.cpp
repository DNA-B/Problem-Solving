#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = my_string.substr(0, s);
    answer += overwrite_string;
    if(answer.length() != my_string.length())
        answer += my_string.substr(answer.length());
    return answer;
}