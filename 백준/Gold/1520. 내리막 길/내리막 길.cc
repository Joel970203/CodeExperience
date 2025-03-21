#include <iostream>
#include <vector>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int M, N;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
vector<vector<int>> graph;
vector<vector<int>> dp; 

int DFS(int y, int x)
{
    if (y == M - 1 && x == N - 1)
        return 1;

    if (dp[y][x] != -1)
        return dp[y][x];

    dp[y][x] = 0;

    for (int i = 0; i < 4; i++)
    {
        int curY = y + dy[i];
        int curX = x + dx[i];

        if (curY >= 0 && curY < M && curX >= 0 && curX < N)
        {
            if (graph[y][x] > graph[curY][curX])
            {
                dp[y][x] += DFS(curY, curX);
            }
        }
    }

    return dp[y][x];
}

int main()
{
    fastio();

    cin >> M >> N;
    graph.resize(M, vector<int>(N));
    dp.resize(M, vector<int>(N, -1)); 

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> graph[i][j];
        }
    }

    cout << DFS(0, 0) << "\n";

    return 0;
}
