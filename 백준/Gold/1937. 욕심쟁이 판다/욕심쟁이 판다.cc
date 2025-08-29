#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
vector<vector<int>> graph;
vector<vector<int>> dp; // 메모이제이션

int dfs(int y, int x) 
{
    if (dp[y][x] != -1) return dp[y][x]; // 이미 계산했으면 반환
    dp[y][x] = 1; // 자기 자신 포함 최소 1칸

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (graph[ny][nx] > graph[y][x]) 
        {
            dp[y][x] = max(dp[y][x], 1 + dfs(ny, nx));
        }
    }
    return dp[y][x];
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    graph.assign(n, vector<int>(n));
    dp.assign(n, vector<int>(n, -1));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];

    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans = max(ans, dfs(i, j));

    cout << ans << "\n";
}
