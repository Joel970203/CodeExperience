#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
vector<vector<char>> graph(50, vector<char>(50, 'W'));
bool visited[50][50] = { 0 };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

// BFS를 수정하여 각 지점에서 가장 먼 거리 계산
int bfs(int x, int y) {
    queue<pair<pair<int, int>, int>> q; // 큐에 좌표와 거리를 함께 저장
    q.push({ {x, y}, 0 });
    visited[x][y] = 1;
    int maxDist = 0; // 가장 먼 거리 저장

    while (!q.empty()) {
        int tempX = q.front().first.first;
        int tempY = q.front().first.second;
        int dist = q.front().second; // 현재까지의 거리
        q.pop();

        maxDist = max(maxDist, dist); // 가장 먼 거리 갱신

        for (int i = 0; i < 4; i++) {
            int curX = tempX + dx[i];
            int curY = tempY + dy[i];

            if (curX >= 0 && curX < N && curY >= 0 && curY < M) {
                // 방문하지 않았고 육지일 경우에만 큐에 추가
                if (!visited[curX][curY] && graph[curX][curY] == 'L') {
                    visited[curX][curY] = 1;
                    q.push({ {curX, curY}, dist + 1 }); // 거리 1 추가하여 큐에 저장
                }
            }
        }
    }

    return maxDist; // 가장 먼 거리 반환
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    int ans = 0; // 최종 정답(가장 먼 거리 저장)

    // 각 육지마다 BFS 수행
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (graph[i][j] == 'L') { // 육지일 경우
                // 방문 배열 초기화
                fill(&visited[0][0], &visited[0][0] + 50 * 50, false);

                // 해당 육지에서 BFS 수행하여 가장 먼 거리 계산
                ans = max(ans, bfs(i, j)); // 최대 거리 갱신
            }
        }
    }

    cout << ans << endl; // 가장 먼 거리 출력

    return 0;
}
