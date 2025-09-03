#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
int dy[4] = {1,-1,0,0};
int dx[4] = {0,0,1,-1};
vector<vector<int>> graph;

void markAir(queue<pair<int,int>>& q) {
    while (!q.empty()) {
        auto [y, x] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int ny = y + dy[d], nx = x + dx[d];
            if (ny<0||ny>=N||nx<0||nx>=M) continue;
            if (graph[ny][nx]==0) {
                graph[ny][nx] = -1;
                q.push({ny,nx});
            }
        }
    }
}

int main() {
    cin >> N >> M;
    graph.assign(N, vector<int>(M));
    for (int i=0;i<N;i++)
        for (int j=0;j<M;j++)
            cin >> graph[i][j];

    // 초기 외부공기 표시
    queue<pair<int,int>> q;
    graph[0][0] = -1;
    q.push({0,0});
    markAir(q);

    int time = 0;
    while (true) {
        vector<pair<int,int>> melt;
        bool hasCheese = false;

        // 이번 턴에 녹을 치즈 찾기
        for (int i=0;i<N;i++) {
            for (int j=0;j<M;j++) {
                if (graph[i][j] == 1) {
                    hasCheese = true;
                    int air = 0;
                    for (int d=0; d<4; d++) {
                        int ny=i+dy[d], nx=j+dx[d];
                        if (graph[ny][nx] == -1) air++;
                    }
                    if (air >= 2) melt.push_back({i,j});
                }
            }
        }

        if (!hasCheese) break; // 치즈 다 녹음

        // 동시에 녹이기
        for (auto [y,x] : melt) {
            graph[y][x] = -1;   // 바로 외부공기로 바꿔주고
            q.push({y,x});      // BFS 확장을 위해 큐에 넣음
        }

        // 외부공기 확장 (한 번만 BFS)
        markAir(q);

        time++;
    }

    cout << time << "\n";
}
