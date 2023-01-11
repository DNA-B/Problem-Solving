#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2)
{
    vector<vector<int>> answer;
    int n = arr1.size();
    int m = arr1[0].size();
    
    for (int i = 0; i < n; i++)
    {
        answer.resize(n);
        for (int j = 0; j < m; j++)
        {
            answer[i].push_back(arr1[i][j] + arr2[i][j]);
        }
    }
    return answer;
}