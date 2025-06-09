#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(vector<int> num_list) {
    int total_plus = 0, total_mult = 1;
    
    for (int num : num_list)
        total_plus += num, total_mult *= num;
    
    return total_mult < pow(total_plus, 2);
}