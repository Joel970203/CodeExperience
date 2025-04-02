#include <vector>
#include <queue>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int solution(vector<vector<int>> maps) 
{
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, int>> q;

    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) 
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) 
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && ny < n && nx >= 0 && nx < m) 
            {
                if (!visited[ny][nx] && maps[ny][nx] == 1) 
                {
                    visited[ny][nx] = true;
                    maps[ny][nx] = maps[y][x] + 1;  
                    q.push({ny, nx});
                }
            }
        }
    }

    int result = maps[n-1][m-1];
    return (result == 1) ? -1 : result;
}
