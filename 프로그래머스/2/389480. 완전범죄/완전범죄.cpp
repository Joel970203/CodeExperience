#include <vector>
#include <algorithm>
using namespace std;

const int INF = 100000; 

int solution(vector<vector<int>> info, int n, int m) 
{
    int size = info.size();
    vector<vector<int>> dp(size + 1, vector<int>(m, INF));

    dp[0][0] = 0;

    for (int i = 1; i <= size; i++) 
    {
        int a = info[i - 1][0];  
        int b = info[i - 1][1];  

        for (int j = 0; j < m; j++) 
        {
            dp[i][j] = min(dp[i][j], dp[i - 1][j] + a);

            if (j + b < m) 
            {
                dp[i][j + b] = min(dp[i][j + b], dp[i - 1][j]);
            }
        }
    }

    int answer = INF;
    for (int j = 0; j < m; j++) 
    {
        answer = min(answer, dp[size][j]);
    }

    return (answer >= n) ? -1 : answer;  
}
