#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define fastio() ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

vector<vector<int>> graph;
vector<vector<bool>> visited;
int N, M;
int maxCnt = 0;

void DFS(int x, int y, int cnt, int sum) {
    if (cnt == 4) {
        maxCnt = max(maxCnt, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int curX = x + dx[i];
        int curY = y + dy[i];

        if (curX >= 0 && curX < M && curY >= 0 && curY < N) {
            if (!visited[curY][curX]) {
                visited[curY][curX] = true;
                DFS(curX, curY, cnt + 1, sum + graph[curY][curX]);
                visited[curY][curX] = false;
            }
        }
    }
}

void findMaxTetromino() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = true;
            DFS(j, i, 1, graph[i][j]);
            visited[i][j] = false;
        }
    }
}

void findMaxTShape() {
    int tx[4] = { -1, 0, 0, 1 };
    int ty[4] = { 0, -1, 1, 0 };
    int max_cross = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int total = graph[i][j];
            int min_su = INT_MAX;
            int count = 0;

            for (int q = 0; q < 4; q++) {
                int nx = i + tx[q];
                int ny = j + ty[q];

                if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                    total += graph[nx][ny];
                    min_su = min(min_su, graph[nx][ny]);
                    count++;
                }
            }

            if (count == 4) {
                total -= min_su;
            }
            max_cross = max(max_cross, total);
        }
    }
    maxCnt = max(maxCnt, max_cross);
}

int main() {
    fastio();
    cin >> N >> M;
    graph.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> graph[i][j];
        }
    }

    findMaxTetromino();
    findMaxTShape();
    cout << maxCnt << endl;
}
