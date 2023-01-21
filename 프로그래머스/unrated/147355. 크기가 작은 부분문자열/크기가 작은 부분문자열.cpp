#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    for(int i = 0; i < t.length() - p.length() + 1; i++)
    {
        if(stoll(t.substr(i, p.length())) <= stoll(p))
            answer++;
    }
    
    return answer;
}