#include <iostream>
#include <vector>
using namespace std;

int R, C, T;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

void spreadDust(vector<vector<int>>& graph)
{
    vector<vector<int>> temp(R, vector<int>(C, 0));

    // 공기청정기는 그대로 유지
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (graph[i][j] == -1) temp[i][j] = -1;
        }
    }

    // 확산 처리
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            if (graph[y][x] > 0) {
                int amount = graph[y][x];
                int share = amount / 5;
                int cnt = 0;

                for (int d = 0; d < 4; d++) {
                    int ny = y + dy[d];
                    int nx = x + dx[d];

                    if (ny < 0 || ny >= R || nx < 0 || nx >= C) continue;
                    if (graph[ny][nx] == -1) continue;

                    temp[ny][nx] += share;
                    cnt++;
                }

                temp[y][x] += amount - share * cnt;
            }
        }
    }

    graph = temp;
}

void circulate(vector<vector<int>>& graph, const vector<pair<int, int>>& air)
{
    int top = air[0].first;
    int bottom = air[1].first;

    // --- 위쪽 (반시계) ---
    for (int y = top - 1; y > 0; y--) graph[y][0] = graph[y - 1][0];
    for (int x = 0; x < C - 1; x++) graph[0][x] = graph[0][x + 1];
    for (int y = 0; y < top; y++) graph[y][C - 1] = graph[y + 1][C - 1];
    for (int x = C - 1; x > 1; x--) graph[top][x] = graph[top][x - 1];
    graph[top][1] = 0;

    // --- 아래쪽 (시계) ---
    for (int y = bottom + 1; y < R - 1; y++) graph[y][0] = graph[y + 1][0];
    for (int x = 0; x < C - 1; x++) graph[R - 1][x] = graph[R - 1][x + 1];
    for (int y = R - 1; y > bottom; y--) graph[y][C - 1] = graph[y - 1][C - 1];
    for (int x = C - 1; x > 1; x--) graph[bottom][x] = graph[bottom][x - 1];
    graph[bottom][1] = 0;
}

int main()
{
    cin >> R >> C >> T;
    vector<vector<int>> graph(R, vector<int>(C));
    vector<pair<int, int>> air;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == -1) {
                air.push_back({ i,j });
            }
        }
    }

    while (T--) {
        spreadDust(graph);
        circulate(graph, air);
    }

    int ans = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (graph[i][j] > 0) ans += graph[i][j];
        }
    }
    cout << ans << "\n";
}
