#include <string>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool isSafe(vector<string> &place, int sy, int sx)
{
    bool visited[5][5] = {false};
    queue<pair<pair<int,int>, int>> q; // ((y,x), 거리)
    q.push({{sy, sx}, 0});
    visited[sy][sx] = true;

    while (!q.empty())
    {
        auto [pos, dist] = q.front(); q.pop();
        int y = pos.first;
        int x = pos.second;

        if (dist >= 2) continue; // 2 이상은 탐색 안 함

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
            if (visited[ny][nx]) continue;
            visited[ny][nx] = true;

            if (place[ny][nx] == 'X') continue; // 파티션이면 막힘
            if (place[ny][nx] == 'P') return false; // 사람 발견 → 거리두기 위반

            q.push({{ny, nx}, dist + 1}); // 빈 공간 'O'는 계속 탐색
        }
    }

    return true; // 위반 없음
}

vector<int> solution(vector<vector<string>> places)
{
    vector<int> answer;

    for (auto &place : places)
    {
        bool ok = true;
        for (int y = 0; y < 5; y++)
        {
            for (int x = 0; x < 5; x++)
            {
                if (place[y][x] == 'P')
                {
                    if (!isSafe(place, y, x))
                    {
                        ok = false;
                        break;
                    }
                }
            }
            if (!ok) break;
        }
        answer.push_back(ok ? 1 : 0);
    }

    return answer;
}
