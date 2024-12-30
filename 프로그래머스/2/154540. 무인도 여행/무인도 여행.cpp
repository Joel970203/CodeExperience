#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

bool visited[101][101] = { false };

int bfs(int x, int y, const vector<string>& maps)
{
    queue<pair<int, int>> q;
    q.push({ x,y });
    int sizeX = maps.size();
    int sizeY = maps[0].size();
    int cnt = maps[x][y] - '0';
    while (!q.empty())
    {
        int tempX = q.front().first;
        int tempY = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int curX = tempX + dx[i];
            int curY = tempY + dy[i];

            if (curX < sizeX && curX >= 0 && curY < sizeY && curY >= 0)
            {
                if (visited[curX][curY] == false && maps[curX][curY] != 'X')
                {
                    visited[curX][curY] = true;
                    cnt += maps[curX][curY] - '0';
                    q.push({ curX,curY });
                }
            }
        }
    }
    return cnt;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    int su;
    for (int i = 0; i < maps.size(); i++)
    {
        for (int j = 0; j < maps[i].size(); j++)
        {
            if (maps[i][j] != 'X' && visited[i][j] == false)
            {
                visited[i][j] = true;
                int su = bfs(i, j, maps);
                answer.push_back(su);
            }
        }
    }

    if (answer.empty())
    {
        answer.push_back(-1);
    }

    sort(answer.begin(), answer.end());
    return answer;
}