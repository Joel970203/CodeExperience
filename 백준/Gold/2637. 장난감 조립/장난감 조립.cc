#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Edge {
    int next, cnt;
};

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> graph(N + 1);
    vector<int> indegree(N + 1, 0);

    for (int i = 0; i < M; i++) 
    {
        int X, Y, K;
        cin >> X >> Y >> K;
        graph[Y].push_back({ X, K }); // Y -> X (X 만들 때 Y 필요)
        indegree[X]++;
    }

    // dp[x][i] = x를 만들 때 필요한 기본부품 i 개수
    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0));

    queue<int> q;

    // 기본 부품(진입 차수 0)
    for (int i = 1; i <= N; i++) 
    {
        if (indegree[i] == 0) 
        {
            q.push(i);
            dp[i][i] = 1; // 자기 자신이 기본 부품
        }
    }

    while (!q.empty()) 
    {
        int cur = q.front(); q.pop();

        for (auto [next, cnt] : graph[cur]) 
        {
            // cur 부품의 dp를 next로 전파
            for (int i = 1; i <= N; i++) {
                dp[next][i] += dp[cur][i] * cnt;
            }
            if (--indegree[next] == 0) {
                q.push(next);
            }
        }
    }

    // 완성품 N 출력
    for (int i = 1; i <= N; i++) {
        if (dp[N][i] > 0) {
            cout << i << " " << dp[N][i] << "\n";
        }
    }
}