#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#define fastio() ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int N, M;
vector<vector<char>> graph;
bool visited[50][50][64] = { false }; // 방문 배열을 3차원으로, [y][x][열쇠 상태]
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

// BFS 구조체
struct State {
    int y, x, dist, keys;
};

int bfs(int startY, int startX) {
    queue<State> q;
    visited[startY][startX][0] = true; // 초기 위치 방문 처리
    q.push({ startY, startX, 0, 0 }); // {y, x, dist, keys}

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        // 목표 지점 '1'에 도달한 경우
        if (graph[cur.y][cur.x] == '1') {
            return cur.dist;
        }

        // 4방향 탐색
        for (int i = 0; i < 4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            if (graph[ny][nx] == '#') continue; // 벽은 통과 불가

            int newKeys = cur.keys;

            if (islower(graph[ny][nx])) { // 소문자 -> 열쇠를 얻음
                newKeys |= (1 << (graph[ny][nx] - 'a')); // 해당 열쇠를 얻었음을 비트로 기록
            }

            if (isupper(graph[ny][nx])) { // 대문자 -> 문을 통과하려면 해당 열쇠가 있어야 함
                if (!(newKeys & (1 << (graph[ny][nx] - 'A')))) continue; // 열쇠가 없다면 통과 불가
            }

            if (!visited[ny][nx][newKeys]) {
                visited[ny][nx][newKeys] = true;
                q.push({ ny, nx, cur.dist + 1, newKeys });
            }
        }
    }

    return -1; // 탈출할 수 없으면 -1 반환
}

int main() {
    fastio();
    cin >> N >> M;

    graph.resize(N, vector<char>(M));
    int startY = -1, startX = -1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == '0') {
                startY = i;
                startX = j;
            }
        }
    }

    int result = bfs(startY, startX);
    cout << result << endl;

    return 0;
}
