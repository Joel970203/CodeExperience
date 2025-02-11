#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int N, M;

// BFS 함수, 벽을 부수지 않은 상태와 부수었을 때의 이동 거리를 계산
int solve(vector<vector<int>>& graph) {
    vector<vector<vector<int>>> visited(N, vector<vector<int>>(M, vector<int>(2, -1))); // 3차원 배열로 visited 관리 (0은 벽을 부수지 않은 상태, 1은 벽을 부순 상태)
    queue<pair<pair<int, int>, int>> q;  // (y, x), 벽을 부수었는지 여부
    q.push({{0, 0}, 0});  // 시작점 (0, 0), 벽을 부수지 않음
    visited[0][0][0] = 1;  // 시작점은 1로 설정

    while (!q.empty()) {
        int curY = q.front().first.first;
        int curX = q.front().first.second;
        int broken = q.front().second;  // 벽을 부수었는지 여부
        q.pop();

        // 목표 지점에 도달한 경우
        if (curY == N - 1 && curX == M - 1) {
            return visited[curY][curX][broken];  // 최단 경로를 반환
        }

        // 상하좌우 탐색
        for (int i = 0; i < 4; i++) {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];

            if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < M) {
                // 벽을 부수지 않은 상태에서 벽이 아닌 곳으로 이동
                if (graph[nextY][nextX] == 0 && visited[nextY][nextX][broken] == -1) {
                    visited[nextY][nextX][broken] = visited[curY][curX][broken] + 1;
                    q.push({{nextY, nextX}, broken});
                }
                // 벽을 부수고 이동하는 경우
                if (graph[nextY][nextX] == 1 && broken == 0 && visited[nextY][nextX][1] == -1) {
                    visited[nextY][nextX][1] = visited[curY][curX][broken] + 1;
                    q.push({{nextY, nextX}, 1});
                }
            }
        }
    }

    return -1;  // 목표 지점에 도달할 수 없는 경우
}

int main() {
    fastio();
    cin >> N >> M;

    vector<vector<int>> graph(N, vector<int>(M));

    // 그래프 입력
    string temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        for (int j = 0; j < M; j++) {
            graph[i][j] = temp[j] - '0';
        }
    }

    int ans = solve(graph);  // BFS를 통해 최단 경로를 구함
    cout << ans << endl;  // 결과 출력

    return 0;
}
