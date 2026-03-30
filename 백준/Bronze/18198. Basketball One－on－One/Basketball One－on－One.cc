#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    
    int scoreA = 0, scoreB = 0;
    bool deuce = false;  // 10-10 이후 win by 2 모드
    
    for(int i = 0; i < s.length(); i += 2) {
        char player = s[i];
        int points = s[i+1] - '0';
        
        if (player == 'A')
            scoreA += points;
        else
            scoreB += points;
        
        if (scoreA == 10 && scoreB == 10)
            deuce = true;
        
        // 게임 종료 조건 확인
        if (deuce) {
            // win by 2
            if (abs(scoreA - scoreB) >= 2) {
                if (scoreA > scoreB)
                    cout << "A" << endl;
                else
                    cout << "B" << endl;
                return 0;
            }
        } else {
            if (scoreA >= 11 || scoreB >= 11) {
                if (scoreA > scoreB)
                    cout << "A" << endl;
                else
                    cout << "B" << endl;
                return 0;
            }
        }
    }
    
    if (scoreA > scoreB)
        cout << "A" << endl;
    else
        cout << "B" << endl;
    
    return 0;
}