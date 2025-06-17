#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
    int answer = 0;
    
    if (is_suffix.length() > my_string.length())
        answer = false;
    else if (my_string.substr(my_string.length() - is_suffix.length(), is_suffix.length()) == is_suffix)
        answer = true;
    
    return answer;
}