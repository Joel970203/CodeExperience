#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>

#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)

using namespace std;

int N, M, T;
vector<vector<int>> graph;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

int bfs(int startY, int startX, int endY, int endX, bool sword) {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    queue<pair<int, pair<int, int>>> q;

    q.push({ 0, {startY, startX} });
    visited[startY][startX] = true;

    while (!q.empty()) {
        int time = q.front().first;
        int y = q.front().second.first;
        int x = q.front().second.second;
        q.pop();

        if (time > T) return -1; // 시간 초과
        if (y == endY && x == endX) {
            return time;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
                if (!visited[ny][nx]) {
                    // 검이 없으면 벽을 통과할 수 없음
                    if (!sword && graph[ny][nx] == 1) continue;

                    visited[ny][nx] = true;
                    q.push({ time + 1, {ny, nx} });
                }
            }
        }
    }

    return -1;
}

int main() {
    fastio();
    cin >> N >> M >> T;
    graph.assign(N, vector<int>(M));
    int sy = -1, sx = -1; // 검의 위치

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 2) {
                sy = i;
                sx = j;
            }
        }
    }

    int min_time = INT_MAX;

    int no_sword_path = bfs(0, 0, N - 1, M - 1, false);
    if (no_sword_path != -1) 
    {
        min_time = min(min_time, no_sword_path);
    }

    int to_sword_path = bfs(0, 0, sy, sx, false);
    if (to_sword_path != -1) 
    {
        int sword_to_princess_path = abs(N - 1 - sy) + abs(M - 1 - sx);
        int total_sword_path = to_sword_path + sword_to_princess_path;
        min_time = min(min_time, total_sword_path);
    }

    if (min_time == INT_MAX || min_time > T) {
        cout << "Fail" << endl;
    }
    else {
        cout << min_time << endl;
    }

    return 0;
}