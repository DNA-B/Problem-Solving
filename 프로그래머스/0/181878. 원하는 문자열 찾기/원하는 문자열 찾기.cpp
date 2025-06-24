#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) { 
    if (pat.length() > myString.length())
        return 0;
    
    for (char& ch : myString)
        ch = tolower(ch);
    
    for (char& ch : pat)
        ch = tolower(ch);
    
    return (myString.find(pat) != string::npos);
}