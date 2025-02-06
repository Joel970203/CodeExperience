#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dy[4] = { 0, -1, 0, 1 }; // 서, 북, 동, 남
int dx[4] = { -1, 0, 1, 0 };

vector<vector<int>> graph;
vector<vector<bool>> visited;
int N, M;

int bfs(int y, int x, vector<vector<int>>& component, int componentIdx) {
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push({ y, x });
    visited[y][x] = true;
    component[y][x] = componentIdx;

    while (!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        cnt++;

        for (int i = 0; i < 4; i++) {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];

            if (nextY < 0 || nextY >= M || nextX < 0 || nextX >= N) continue; // 범위 체크
            if (visited[nextY][nextX]) continue;

            // 벽이 있는지 체크 (비트 검사)
            if (graph[curY][curX] & (1 << i)) continue;

            visited[nextY][nextX] = true;
            component[nextY][nextX] = componentIdx;
            q.push({ nextY, nextX });
        }
    }

    return cnt;
}

int main() {
    cin >> N >> M;
    graph.resize(M, vector<int>(N));
    visited.resize(M, vector<bool>(N, false));
    vector<vector<int>> component(M, vector<int>(N, -1)); // 각 방의 컴포넌트 번호 저장

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    int roomCnt = 0;
    int maxRoomSize = 0;
    vector<int> componentSizes;

    // BFS 탐색으로 방 크기 계산
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                int roomSize = bfs(i, j, component, roomCnt);
                maxRoomSize = max(maxRoomSize, roomSize);
                componentSizes.push_back(roomSize);
                roomCnt++;
            }
        }
    }

    // 벽 하나 제거 후 최대 방 크기 찾기
    int maxMergedRoomSize = maxRoomSize;

    for (int y = 0; y < M; y++) {
        for (int x = 0; x < N; x++) {
            for (int i = 0; i < 4; i++) {
                int nextY = y + dy[i];
                int nextX = x + dx[i];

                if (nextY < 0 || nextY >= M || nextX < 0 || nextX >= N) continue;

                // 다른 컴포넌트인 경우만 벽 제거 고려
                if (component[y][x] != component[nextY][nextX]) {
                    maxMergedRoomSize = max(maxMergedRoomSize,
                        componentSizes[component[y][x]] + componentSizes[component[nextY][nextX]]);
                }
            }
        }
    }

    cout << roomCnt << endl;
    cout << maxRoomSize << endl;
    cout << maxMergedRoomSize << endl;

    return 0;
}
