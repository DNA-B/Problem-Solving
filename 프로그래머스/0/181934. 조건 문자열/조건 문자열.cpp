#include <string>
#include <vector>

using namespace std;

int solution(string ineq, string eq, int n, int m) {
    if (ineq == "<" && eq == "=")
        return n <= m;
    else if (ineq == "<" && eq == "!")
        return n < m;
    else if (ineq == ">" && eq == "=")
        return n >= m;
    else if (ineq == ">" && eq == "!")
        return n > m;
}