#include <iostream>
#include <vector>
#include <queue>
#include <cstring> // for memset
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int flood[100][100] = { 0 };
int visited[100][100] = { 0 };
int N, M, K;
int high = 0;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

void dfs(int x1, int x2, int height)
{
    visited[x1][x2] = 1;
    for (int u = 0; u < 4; u++)
    {
        int tempX = x2 + dx[u];
        int tempY = x1 + dy[u];
        if (tempX >= 0 && tempX < M && tempY >= 0 && tempY < N
            && flood[tempY][tempX] >= height && visited[tempY][tempX] == 0)
        {
            dfs(tempY, tempX, height);
        }
    }
}

int main()
{
    fastio();
    cin >> N;
    M = N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> flood[i][j];
            if (flood[i][j] > high)
            {
                high = flood[i][j];
            }
        }
    }

    int answer = 0;
    for (int h = 1; h <= high; h++)
    {
        int cnt = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (flood[i][j] >= h && visited[i][j] == 0)
                {
                    dfs(i, j, h);
                    cnt++;
                }
            }
        }
        if (cnt > answer)
        {
            answer = cnt;
        }
    }
    cout << answer << endl;
    return 0;
}
