#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int bfs(const vector<string>& maps, int startX, int startY, char target)
{
    int n = maps.size();
    int m = maps[0].size();
    bool visited[100][100] = { false };
    queue<pair<int, int>> q;
    q.push({ startX, startY });
    visited[startX][startY] = true;
    int cnt = 0;

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

                if (curX >= 0 && curY >= 0 && curX < n && curY < m && !visited[curX][curY])
                {
                    if (maps[curX][curY] != 'X') // 'X'는 벽, 지나갈 수 없음
                    {
                        if (maps[curX][curY] == target) // 목표에 도달하면
                        {
                            return cnt + 1; // 목표 지점에 도달한 최단 경로를 리턴
                        }
                        q.push({ curX, curY });
                        visited[curX][curY] = true;
                    }
                }
            }
        }
        cnt++; // 한 레벨을 다 처리하고 나서 카운트 증가
    }
    return -1; // 목표 지점에 도달할 수 없다면 -1 리턴
}

int solution(vector<string> maps) {
    int c1 = 0;
    int c2 = 0;
    int startX = 0, startY = 0, leverX = 0, leverY = 0, exitX = 0, exitY = 0;

    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[0].size(); j++)
        {
            if (maps[i][j] == 'S')
            {
                startX = i;
                startY = j;
            }
            else if (maps[i][j] == 'L')
            {
                leverX = i;
                leverY = j;
            }
            else if (maps[i][j] == 'E')
            {
                exitX = i;
                exitY = j;
            }
        }
    }

    // S -> L
    c1 = bfs(maps, startX, startY, 'L');
    if (c1 == -1) return -1;

    // L -> E
    c2 = bfs(maps, leverX, leverY, 'E');
    if (c2 == -1) return -1;

    return c1 + c2;
}
