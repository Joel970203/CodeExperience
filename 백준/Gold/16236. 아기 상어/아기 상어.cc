#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int N;
vector<vector<int>> graph;
int sy, sx; // 상어 위치
int sharkSize = 2, eatCount = 0, totalTime = 0;

// 방향: 위, 왼, 오른, 아래 (우선순위 맞추기 위해 위→왼→오른→아래)
int dy[4] = {-1, 0, 0, 1};
int dx[4] = {0, -1, 1, 0};

// BFS로 먹을 물고기 찾기
pair<int,int> bfs() {
    vector<vector<int>> dist(N, vector<int>(N, -1));
    queue<pair<int,int>> q;
    q.push({sy, sx});
    dist[sy][sx] = 0;

    int minDist = INT_MAX;
    pair<int,int> target = {-1, -1};

    while(!q.empty()) {
        auto [y,x] = q.front(); q.pop();

        for(int dir=0; dir<4; dir++) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];

            if(ny<0 || nx<0 || ny>=N || nx>=N) continue;
            if(dist[ny][nx] != -1) continue;        // 이미 방문
            if(graph[ny][nx] > sharkSize) continue; // 큰 물고기 못 지나감

            dist[ny][nx] = dist[y][x] + 1;

            // 먹을 수 있는 물고기라면 후보 갱신
            if(graph[ny][nx] != 0 && graph[ny][nx] < sharkSize) {
                if(dist[ny][nx] < minDist ||
                   (dist[ny][nx] == minDist && (ny < target.first ||
                   (ny == target.first && nx < target.second)))) {
                    minDist = dist[ny][nx];
                    target = {ny, nx};
                }
            }

            q.push({ny, nx});
        }
    }

    if(target.first == -1) return {-1,-1}; // 먹을 수 있는 물고기 없음
    totalTime += minDist;
    return target;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    graph.assign(N, vector<int>(N));

    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> graph[i][j];
            if(graph[i][j] == 9) {
                sy = i; sx = j;
                graph[i][j] = 0; // 상어 출발 위치는 빈 칸으로
            }
        }
    }

    while(true) {
        auto target = bfs();
        if(target.first == -1) break; // 더 이상 먹을 물고기 없음

        // 물고기 먹기
        sy = target.first; 
        sx = target.second;
        graph[sy][sx] = 0;
        eatCount++;

        if(eatCount == sharkSize) { // 상어 크기 업그레이드
            sharkSize++;
            eatCount = 0;
        }
    }

    cout << totalTime << "\n";
}
