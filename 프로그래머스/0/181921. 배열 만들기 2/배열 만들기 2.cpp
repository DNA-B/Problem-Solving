#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool is_zero_five(string s) {
    for (char ch : s) {
        if (ch != '0' && ch != '5')
            return false;
    }
    
    return true;
}

vector<int> solution(int l, int r) {
    vector<int> answer;
    
    for (int i = l; i <= r; i++) {
        if (is_zero_five(to_string(i)))
            answer.push_back(i);
    }
    
    if (answer.empty()) 
        answer.push_back(-1);
    
    return answer;
}