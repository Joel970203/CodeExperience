#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 8방향 이동을 위한 dx, dy 설정
int dx[8] = { 1, -1, 0, 0, -1, 1, -1, 1 };
int dy[8] = { 0, 0, 1, -1, -1, -1, 1, 1 };

// BFS 탐색 함수
bool bfs(int x, int y, int N, int M, const vector<vector<int>>& graph, vector<vector<bool>>& visited) {
    queue<pair<int, int>> q;
    q.push({ x, y });
    visited[x][y] = true;

    bool is_peak = true; // 산봉우리인지 여부
    int height = graph[x][y];

    // BFS 탐색 시작
    while (!q.empty()) {
        int tempX = q.front().first;
        int tempY = q.front().second;
        q.pop();

        // 8방향에 대해 탐색
        for (int i = 0; i < 8; i++) {
            int curX = tempX + dx[i];
            int curY = tempY + dy[i];

            // 인접 좌표가 유효한지 확인
            if (curX >= 0 && curX < N && curY >= 0 && curY < M) {
                // 인접한 곳이 더 높은 지점이 있으면 산봉우리가 아님
                if (graph[curX][curY] > height) {
                    is_peak = false;
                }

                // 같은 높이인 경우, 이어서 탐색
                if (!visited[curX][curY] && graph[curX][curY] == height) {
                    visited[curX][curY] = true;
                    q.push({ curX, curY });
                }
            }
        }
    }

    return is_peak;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<int>> graph(N, vector<int>(M));
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    // 농장 격자 높이 입력 받기
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    int peak_count = 0; // 산봉우리 개수

    // 모든 좌표에 대해 BFS 탐색 실행
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 아직 방문하지 않은 지점에 대해 BFS 탐색
            if (!visited[i][j]) {
                if (bfs(i, j, N, M, graph, visited)) {
                    peak_count++;
                }
            }
        }
    }

    // 산봉우리 개수 출력
    cout << peak_count << endl;

    return 0;
}