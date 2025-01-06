#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
#include <cstring>
bool visited[100][100] = { false };
using namespace std;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int cnt;


int bfs_end(int x, int y, const vector<string>& maps)
{
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = true;
    cnt = 0;
    while (!q.empty())
    {
        int size = q.size(); // 현재 큐에 남아있는 요소들의 개수를 저장 (한 레벨에서 한 번에 다가가기)
        for (int k = 0; k < size; k++) // 한 레벨씩 처리
        {
            int tempX = q.front().first;
            int tempY = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int curX = tempX + dx[i];
                int curY = tempY + dy[i];

                if (curX >= 0 && curY >= 0 && curX < maps.size() && curY < maps[0].size() && !visited[curX][curY])
                {
                    if (maps[curX][curY] != 'X')
                    {
                        if (maps[curX][curY] == 'E')
                        {
                            return cnt + 1; // 목표 'E'에 도달하면 cnt 반환 (여기서 바로 리턴)
                        }
                        q.push({ curX, curY });
                        visited[curX][curY] = true;
                    }
                }
            }
        }
        cnt++; // 한 번에 큐에서 하나의 레벨을 처리하고 나서 카운트 증가
    }
    return -1;
}

int bfs_lever(int x, int y, const vector<string>& maps)
{
    queue<pair<int, int>> q;
    q.push({ x,y });
    visited[x][y] = true;
    cnt = 0;
    while (!q.empty())
    {
        int size = q.size(); // 현재 큐에 남아있는 요소들의 개수를 저장 (한 레벨에서 한 번에 다가가기)
        for (int k = 0; k < size; k++) // 한 레벨씩 처리
        {
            int tempX = q.front().first;
            int tempY = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int curX = tempX + dx[i];
                int curY = tempY + dy[i];

                if (curX >= 0 && curY >= 0 && curX < maps.size() && curY < maps[0].size() && !visited[curX][curY])
                {
                    if (maps[curX][curY] != 'X')
                    {
                        if (maps[curX][curY] == 'L')
                        {
                            return cnt + 1; // 목표 'L'에 도달하면 cnt 반환 (여기서 바로 리턴)
                        }
                        q.push({ curX, curY });
                        visited[curX][curY] = true;
                    }
                }
            }
        }
        cnt++; // 한 번에 큐에서 하나의 레벨을 처리하고 나서 카운트 증가
    }
    return -1;
}


int solution(vector<string> maps) {
    int c1 = 0;
    int c2 = 0;
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[0].size(); j++)
        {
            if (maps[i][j] == 'S')
            {
                c1 = bfs_lever(i, j, maps);
                if (c1 == -1)
                    return -1;

                memset(visited, false, sizeof(visited));
            }

            if (maps[i][j] == 'L')
            {
                c2 = bfs_end(i, j, maps);
                if (c2 == -1)
                    return -1;
                memset(visited, false, sizeof(visited));
            }
        }
    }
    return c1 + c2;
}