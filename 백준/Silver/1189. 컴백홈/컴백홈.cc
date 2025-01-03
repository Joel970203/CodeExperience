#include <iostream>
#include <vector>
using namespace std;

int R, C, K;
int dx[4] = { 1, -1, 0, 0 }; 
int dy[4] = { 0, 0, 1, -1 };
int count = 0;
bool visited[5][5] = { false };

void dfs(int x, int y, vector<vector<char>>& graph, int dist)
{
    if (x == 0 && y == (C - 1)) {
        if (dist == K) {
            count++;
        }
        return;
    }

    visited[x][y] = true; // 현재 위치 방문 처리

    for (int i = 0; i < 4; i++)
    {
        int tempX = x + dx[i];
        int tempY = y + dy[i];

        if (tempX >= 0 && tempX < R && tempY >= 0 && tempY < C) {
            if (!visited[tempX][tempY] && graph[tempX][tempY] != 'T') {
                dfs(tempX, tempY, graph, dist + 1); 
            }
        }
    }

    visited[x][y] = false; // 재귀 호출 후 현재 위치 방문 해제
}

int main()
{
    cin >> R >> C >> K;

    vector<vector<char>> graph(R, vector<char>(C));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> graph[i][j];
        }
    }

    visited[R - 1][0] = true; 
    dfs(R - 1, 0, graph, 1); 
    cout << count << endl; 

    return 0;
}