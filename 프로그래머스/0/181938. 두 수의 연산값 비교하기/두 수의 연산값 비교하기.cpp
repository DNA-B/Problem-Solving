#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    int ab = stoi(to_string(a) + to_string(b));
    int two_ab = 2 * a * b;
    return max(ab, two_ab);
}