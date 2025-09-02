#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

int R, C;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int answer = INT_MAX;

int main()
{
    cin >> R >> C;

    vector<vector<char>> graph(R, vector<char>(C));
    vector<vector<int>> fire(R, vector<int>(C, -1)); // 불 도착 시간
    vector<vector<int>> man(R, vector<int>(C, -1));  // 지훈 도착 시간

    int manY, manX;
    queue<pair<int, int>> q1; 

    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
        {
            char k;
            cin >> k;
            if (k == 'F')
            {
                fire[i][j] = 0;
                q1.push({ i, j });
            }
            else if (k == 'J')
            {
                man[i][j] = 0;
                manY = i;
                manX = j;
            }
            graph[i][j] = k;
        }

    if (manY == 0 || manY == R - 1 || manX == 0 || manX == C - 1) {
        cout << 1 << "\n";
        return 0;
    }

    while (!q1.empty())
    {
        auto [y, x] = q1.front();
        q1.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
            if (graph[ny][nx] == '#' || fire[ny][nx] != -1) continue; 

            fire[ny][nx] = fire[y][x] + 1;
            q1.push({ ny,nx });
        }
    }

    queue<pair<int, int>> q2;
    q2.push({ manY,manX });

    while (!q2.empty())
    {
        auto [y, x] = q2.front();
        q2.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= R || nx < 0 || nx >= C)
            {
                cout << man[y][x] + 1 << "\n";
                return 0;
            }

            if (graph[ny][nx] == '#' || man[ny][nx] != -1) continue;
            if (fire[ny][nx] != -1 && fire[ny][nx] <= man[y][x] + 1) continue;

            man[ny][nx] = man[y][x] + 1;
            q2.push({ ny,nx });
        }

    }

    cout << "IMPOSSIBLE" << endl;
}
