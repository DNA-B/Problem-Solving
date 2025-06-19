#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_prefix) {
    if (is_prefix.length() > my_string.length())
        return 0;
    
    for (int i = 1; i <= my_string.length(); i++) {
        if (my_string.substr(0, i) == is_prefix)
            return 1;
    }
    
    return 0;
}