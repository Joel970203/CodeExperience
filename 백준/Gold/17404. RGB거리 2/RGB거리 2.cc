#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> graph(N + 1, vector<int>(3));

    for (int i = 1; i <= N; i++) {
        cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
    }

    int answer = INF;

    for (int first = 0; first < 3; first++) {
        vector<vector<int>> dp(N + 1, vector<int>(3, INF));

        dp[1][first] = graph[1][first];

        for (int i = 2; i <= N; i++) {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + graph[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + graph[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + graph[i][2];
        }

        for (int last = 0; last < 3; last++) {
            if (last == first) continue; // 첫 색과 마지막 색 달라야 함
            answer = min(answer, dp[N][last]);
        }
    }

    cout << answer << "\n";
}
