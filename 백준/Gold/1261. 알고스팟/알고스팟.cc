#include <bits/stdc++.h>
using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };

int main() {
    int M, N;
    cin >> M >> N; // ⚠️ M=가로, N=세로

    vector<vector<int>> graph(N, vector<int>(M));
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            graph[i][j] = s[j] - '0';
        }
    }

    deque<pair<int, int>> dq;
    vector<vector<int>> dist(N, vector<int>(M, 1e9));

    dist[0][0] = 0;
    dq.push_front({ 0,0 });

    while (!dq.empty()) {
        auto [y, x] = dq.front(); dq.pop_front();

        for (int d = 0; d < 4; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

            int cost = dist[y][x] + graph[ny][nx];
            if (cost < dist[ny][nx]) {
                dist[ny][nx] = cost;
                if (graph[ny][nx] == 0) dq.push_front({ ny,nx });
                else dq.push_back({ ny,nx });
            }
        }
    }

    cout << dist[N - 1][M - 1] << "\n";
}
