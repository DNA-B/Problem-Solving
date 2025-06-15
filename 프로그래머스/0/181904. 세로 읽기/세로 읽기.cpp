#include <string>
#include <vector>

using namespace std;

string solution(string my_string, int m, int c) {
    string answer = "";
    
    for (int i = 0; i < my_string.length() / m; i++) {
        for (int j = 0; j < m; j++)
            if (j == c - 1) answer += my_string[i * m + j];
    }
    
    return answer;
}