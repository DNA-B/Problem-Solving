#include <string>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;
    
    // i = height
    for (int i = 3; ; i++) {
        if (total % i == 0) 
        {
            int weight = total / i;
            
            if (((i - 2) * (weight - 2)) == yellow) 
            {
                answer.push_back(weight);
                answer.push_back(i);
                break;
            }
        }
    }
    return answer;
}