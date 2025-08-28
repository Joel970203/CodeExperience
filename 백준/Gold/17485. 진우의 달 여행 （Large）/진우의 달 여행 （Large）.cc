#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> graph[i][j];

    const int INF = 1e9;
    vector<vector<vector<int>>> dp(N, vector<vector<int>>(M, vector<int>(3, INF)));

    for (int j = 0; j < M; j++) 
    {
        for (int d = 0; d < 3; d++) 
        {
            dp[0][j][d] = graph[0][j];
        }
    }

    for (int i = 1; i < N; i++) 
    {
        for (int j = 0; j < M; j++)
        {
            // 왼쪽 대각선 ↙
            if (j < M - 1) 
            {
                dp[i][j][0] = min(dp[i][j][0],
                    min(dp[i - 1][j + 1][1], dp[i - 1][j + 1][2]) + graph[i][j]);
            }
            // 아래 ↓
            dp[i][j][1] = min(dp[i][j][1],
                min(dp[i - 1][j][0], dp[i - 1][j][2]) + graph[i][j]);
            // 오른쪽 대각선 ↘
            if (j > 0) 
            {
                dp[i][j][2] = min(dp[i][j][2],
                    min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + graph[i][j]);
            }
        }
    }
    int ans = INF;
    for (int j = 0; j < M; j++) 
    {
        for (int d = 0; d < 3; d++) 
        {
            ans = min(ans, dp[N - 1][j][d]);
        }
    }
    cout << ans << "\n";
    return 0;
}
