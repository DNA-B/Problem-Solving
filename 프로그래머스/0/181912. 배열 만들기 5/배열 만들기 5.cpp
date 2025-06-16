#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> intStrs, int k, int s, int l) {
    vector<int> answer;
    
    for (string str : intStrs) {
        string tmp = str.substr(s, l);
        int tmp_int = stoi(tmp);
        if (tmp_int > k) answer.push_back(tmp_int);
    }
    
    return answer;
}