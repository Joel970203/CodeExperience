#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N, L, R;
vector<vector<int>> graph;
vector<vector<bool>> visited;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool bfs(int startY, int startX) 
{
    queue<pair<int, int>> q;
    vector<pair<int, int>> unionCells;

    q.push({ startY, startX });
    visited[startY][startX] = true;
    unionCells.push_back({ startY, startX });

    int totalPopulation = graph[startY][startX]; 
    int countryCount = 1;

    while (!q.empty()) 
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) 
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && ny < N && nx >= 0 && nx < N && !visited[ny][nx]) 
            {
                int populationDiff = abs(graph[ny][nx] - graph[y][x]);
                if (populationDiff >= L && populationDiff <= R) 
                {
                    visited[ny][nx] = true;
                    q.push({ ny, nx });
                    unionCells.push_back({ ny, nx });
                    totalPopulation += graph[ny][nx];
                    countryCount++;
                }
            }
        }
    }

    if (countryCount > 1) 
    {
        int newPopulation = totalPopulation / countryCount;
        for (auto& cell : unionCells) 
        {
            graph[cell.first][cell.second] = newPopulation;
        }
        return true; 
    }

    return false; 
}

int main() 
{
    cin >> N >> L >> R;
    graph.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
        {
            cin >> graph[i][j];
        }
    }

    int days = 0;

    while (true) 
    {
        visited.assign(N, vector<bool>(N, false)); 
        bool moved = false; // 오늘 인구 이동이 있었는지 확인

        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < N; j++) 
            {
                if (!visited[i][j]) 
                {
                    if (bfs(i, j))
                    {
                        moved = true;
                    }
                }
            }
        }

        if (!moved) break; // 더 이상 인구 이동이 없으면 종료
        days++;
    }

    cout << days << endl;
    return 0;
}
